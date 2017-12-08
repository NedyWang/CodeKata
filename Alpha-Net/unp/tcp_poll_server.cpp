//
// Created by root on 12/7/17.
//
#include <sys/socket.h>
#include <netinet/in.h>
#include <cstring>
#include <poll.h>
#include <cstdio>
#include <iostream>
#include <zconf.h>

#define PORT 8787
#define MAX_LEN 1024
#define MAX_CONNECTIONS 1000

void tcp_poll_server()
{
    int listen_fd = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in server_addr, client_addr;
    bzero(&server_addr, sizeof(server_addr));
    bzero(&client_addr, sizeof(client_addr));

    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    server_addr.sin_port = htons(PORT);
    server_addr.sin_family = AF_INET;

    bind(listen_fd, (struct sockaddr*)&server_addr, sizeof(server_addr));
    listen(listen_fd, 5);

    struct pollfd poll_set[MAX_CONNECTIONS];
    for(int i = 1; i < MAX_CONNECTIONS; ++i) {
        poll_set[i].fd = -1;
    }

    poll_set[0].fd = listen_fd;
    poll_set[0].events = POLLRDNORM;

    int numbers = 1;
    char buf[MAX_LEN];

    while (true) {
        int n_ready = poll(poll_set, numbers, -1);

        if (n_ready > 0) {
            if (poll_set[0].revents == POLLIN) {
                --n_ready;
                socklen_t client_addr_len = sizeof(client_addr);
                int client_fd = accept(poll_set[0].fd, (struct sockaddr*)&client_addr, &client_addr_len);
                bool is_full = true;
                for(int i = 1; i < MAX_CONNECTIONS; ++i) {
                    if (poll_set[i].fd == -1) {
                        continue;
                    }
                    is_full = false;
                    poll_set[i].fd = client_fd;
                    ++ numbers;
                }
                if (is_full) {
                    std::cout<< "too many client connections." << std::endl;
                    close(client_fd);
                }
            }
            int i = 1;
            while(n_ready > 0 and i < MAX_CONNECTIONS) {
                if (poll_set[i].revents == POLLIN) {
                    int n = read(poll_set[i].fd, buf, MAX_LEN);
                    if (n == 0) {
                        // the connection is closed by client
                        shutdown(poll_set[i].fd, SHUT_RDWR);
                        poll_set[i].fd = -1;
                        -- numbers;
                    } else if (n < 0) {
                        std::cout << "RST reveived" << std::endl;
                        shutdown(poll_set[i].fd, SHUT_RD);
                        poll_set[i].fd = -1;
                        -- numbers;
                    } else {
                        write(poll_set[i].fd, buf, sizeof(buf));
                    }
                    --n_ready;
                }
                ++i;
            }
        }
    }
}
