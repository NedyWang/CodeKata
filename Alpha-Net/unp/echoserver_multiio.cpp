//
// Created by root on 12/9/17.
//

#include <netinet/in.h>
#include <unistd.h>
#include <string.h>
#include <iostream>
#include "unp.h"

#define MAX_LEN 1024
#define SERVER_PORT 8787

void echoserver_select()
{
    struct sockaddr_in server_address, client_address;

    bzero(&server_address, sizeof(server_address));
    server_address.sin_addr.s_addr = htonl(INADDR_ANY);
    server_address.sin_port = htons(SERVER_PORT);
    server_address.sin_family = AF_INET;

    int listen_fd = socket(AF_INET, SOCK_STREAM, 0);
    bind(listen_fd, (struct sockaddr*)&server_address, sizeof(server_address));
    listen(listen_fd, 5);


    int client_fds[FD_SETSIZE];
    for (auto i = 0; i < FD_SETSIZE; ++i) {
        client_fds[i] = -1;
    }

    int max_fd = listen_fd;
    int max_i = 0;
    char buf[MAX_LEN];

    fd_set all_set, rset;
    FD_ZERO(&all_set);
    FD_SET(listen_fd, &all_set);

    while (true) {
        rset = all_set;
        int n_ready = select(max_fd + 1, &rset, nullptr, nullptr, nullptr);
        if (FD_ISSET(listen_fd, &rset)) {
            socklen_t client_len = sizeof(client_address);
            int conn_fd = accept(listen_fd, (struct sockaddr *) &client_address, &client_len);
            int i = 0;
            while (i < FD_SETSIZE) {
                if (client_fds[i] != -1) {
                    ++i;
                    continue;
                }
                client_fds[i] = conn_fd;
                max_i = std::max(max_i, i);
                max_fd = std::max(max_fd, conn_fd);
                FD_SET(conn_fd, &all_set);
                break;
            }
            if (i == FD_SETSIZE) {
                close(conn_fd);
                std::cerr << "too many client connection, refuse it." << std::endl;
            } else {
                --n_ready;
                continue;
            }
        }
        for (int i = 0; i <= max_i; ++i) {
            if (client_fds[i] == -1) {
                continue;
            }
            if (FD_ISSET(client_fds[i], &rset)) {
                int n = read(client_fds[i], buf, MAX_LEN);
                if (n < 0) {
                    if (errno == ECONNREFUSED) {
                        /*RST received. connection reset by client */
                        close(client_fds[i]);
                        client_fds[i] = -1;
                    } else {
                        std::cerr << "read error" << std::endl;
                    }
                } else if (n == 0) {
                    /* FIN received */
                    close(client_fds[i]);
                    FD_CLR(client_fds[i], &all_set);
                    client_fds[i] = -1;
                } else {
                    writen(client_fds[i], buf, n);
                }
                if (--n_ready <= 0) {
                    break;
                }
            }
        }
    }
}



#include <poll.h>
#define OPEN_MAX 1024

void echoserver_poll()
{
    int listen_fd;
    listen_fd = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in server_adddress, client_address;
    bzero(&server_adddress, sizeof(server_adddress));
    server_adddress.sin_family = AF_INET;
    server_adddress.sin_port = htons(SERVER_PORT);
    server_adddress.sin_addr.s_addr = htonl(INADDR_ANY);
    bind(listen_fd, (struct sockaddr*)&server_adddress, sizeof(server_adddress));

    listen(listen_fd, 5);

    int max_i = 1;
    struct pollfd client[OPEN_MAX];
    client[0].fd = listen_fd;
    client[0].events = POLLRDNORM;
    char buf[MAX_LEN];

    for (int i = 1; i < OPEN_MAX; ++i) {
        client[i].fd = -1;
    }

    while(true) {
        int n_ready = poll(client, max_i, -1);
        if (client[0].revents & POLLRDNORM) {
            socklen_t client_len = sizeof(client_address);
            int conn_fd = accept(client[0].fd, (struct sockaddr*)&client_address, &client_len);
            int i = 1;
            while( i < OPEN_MAX) {
                if(client[i].fd == -1) {
                    client[i].fd = conn_fd;
                    break;
                }
                ++i;
            }
            if (i == OPEN_MAX) {
                std::cout <<"too many client connections" << std::endl;
            }
            if (i > max_i) {
                max_i = i;
            }

            if (--n_ready <=0 ) {
                continue;
            }
        }

        for (int i = 1; i <= max_i; ++i) {
            if (client[i].fd == -1) {
                continue;
            }
            if (client[i].revents & (POLLRDNORM | POLLERR)) {
                int n = read(client[i].fd, buf, MAX_LEN);
                if (n < 0) {
                    if (errno == ECONNREFUSED) {
                        /*RST received. connection reset by client */
                        close(client[i].fd);
                        client[i].fd = -1;
                    } else {
                        std::cerr << "read error" << std::endl;
                    }
                } else if (n == 0) {
                    /*FIN received */
                    close(client[i].fd);
                    client[i].fd = -1;
                } else {
                    writen(client[i].fd, buf, n);
                }
                if (--n_ready <= 0) {
                    break;
                }
            }
        }
    }
}
int main(int argc, char **argv)
{
    echoserver_select();
    return 0;
}
