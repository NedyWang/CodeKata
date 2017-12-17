//
// Created by root on 12/14/17.
//

#include <fcntl.h>
#include <sys/epoll.h>
#include <netinet/in.h>
#include <errno.h>
#include <cstring>
#include "unp.h"

#define MAX_LEN 1024
#define LISTEN_PORT 8080
#define LISTEN_QUEUE_LEN 5
#define MAX_EVENT_NUMBER 1024

/**
 * set fd as no-block fd
 * @param fd file description
 */

int setNoBlocking(int fd)
{
    int original_option = fcntl(fd, F_GETFL);
    int option = original_option | O_NONBLOCK;
    fcntl(fd, F_SETFL, option);
    return original_option;
}

/**
 * Add fd to efd epoll event table
 * @param efd: epoll ctl fd
 * @param fd: fd to be added into efd table
 * @param et: set fd as ET model
 */
void addEvent(int efd, int fd, bool et = false)
{
    epoll_event event;
    event.data.fd = fd;
    event.events = EPOLLIN;
    if (et) {
        event.events |= EPOLLET;
    }
    setNoBlocking(fd);
    epoll_ctl(efd, EPOLL_CTL_ADD, fd, &event);
}


/**
 * epoll server demo, LT(level trigle) model
 * @param: efd
 * @param: listen_fd
 * @param: events
 * @param: number
 */
void ltModel(int efd, int listen_fd, epoll_event *events, int number)
{
    char buf[MAX_LEN];
    for (auto i = 0; i < number; ++i) {
        int sock_fd = events[i].data.fd;
        if (sock_fd == listen_fd) {
            struct sockaddr_in client_address;
            socklen_t client_len = sizeof(client_address);
            int conn_fd = accept(listen_fd, (struct sockaddr *) &client_address, &client_len);
            addEvent(efd, conn_fd);
        } else if (events[i].events & EPOLLIN) {
            int n = read(sock_fd, buf, MAX_LEN);
            if (n < 0) {
                if (errno == ECONNREFUSED) {
                    epoll_ctl(efd, EPOLL_CTL_DEL, sock_fd, &events[i]);
                    close(sock_fd);
                }
            } else if (n == 0) {
                epoll_ctl(efd, EPOLL_CTL_DEL, sock_fd, &events[i]);
            } else {
                writen(sock_fd, buf, n);
            }
        } else {
            continue;
        }
    }

}

/**
 * epoll server demo, ET(edge trigle model)
 * @param efd:
 * @param listen_fd:
 * @param events:
 * @param number
 */

void etModel(int efd, int listen_fd, epoll_event *events, int number)
{
    char buf[MAX_LEN];
    for (auto i = 0; i < number; ++i) {
        int sock_fd = events[i].data.fd;
        if (sock_fd == listen_fd) {
            struct sockaddr_in client_address;
            socklen_t client_address_len = sizeof(client_address);
            int conn_fd = accept(listen_fd, (struct sockaddr *) &client_address,
                                 &client_address_len);
            addEvent(efd, conn_fd, true);
        } else if (events[i].events & EPOLLIN) {
            while (true) {
                memset(buf, '\0', MAX_LEN);
                int n = read(sock_fd, buf, MAX_LEN);
                if (n < 0) {
                    if (errno == ECONNREFUSED) {
                        epoll_ctl(efd, EPOLL_CTL_DEL, sock_fd, &events[i]);
                        close(sock_fd);
                    } else if (errno == EWOULDBLOCK || errno == EAGAIN) {
                        // This is no-block fd, if no data can read, EWOULDBLOCK set
                        break;
                    } else {
                        continue;
                    }
                } else if (n == 0) {
                    epoll_ctl(efd, EPOLL_CTL_DEL, sock_fd, &events[i]);
                    close(sock_fd);
                } else {
                    writen(sock_fd, buf, n);
                }
            }
        }
    }
}

/**
 * create a epoll server demo
 * @param et: EdgeModel or LevelModel
 */

void epoll_server(bool et = false)
{
    struct sockaddr_in server_address;
    server_address.sin_addr.s_addr = htonl(INADDR_ANY);
    server_address.sin_port = htons(LISTEN_PORT);
    server_address.sin_family = AF_INET;

    int listen_fd = socket(AF_INET, SOCK_STREAM, 0);
    bind(listen_fd, (struct sockaddr*)&server_address, sizeof(server_address));
    listen(listen_fd, LISTEN_QUEUE_LEN);

    epoll_event events[MAX_EVENT_NUMBER];
    int efd = epoll_create(0);
    addEvent(efd, listen_fd);

    auto handler = et ? ltModel: etModel;

    while(true) {
        int n = epoll_wait(efd, events, MAX_EVENT_NUMBER, -1);
        handler(efd, listen_fd, events, n);
    }
}
