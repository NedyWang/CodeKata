//
// Created by root on 12/7/17.
//

#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <iostream>
#include <zconf.h>

#define PORT 8787
#define MAX_LEN 1024

void tcp_select_server()
{
    int client_fds[FOPEN_MAX];
    int listen_fd = socket(AF_INET, SOCK_STREAM, 0);

    struct sockaddr_in server_addr, client_addr;
    bzero(&server_addr, sizeof(server_addr));
    bzero(&client_addr, sizeof(client_addr));

    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    server_addr.sin_port = htons(PORT);
    server_addr.sin_family = AF_INET;

    bind(listen_fd, (struct sockaddr*)&server_addr, sizeof(server_addr));
    listen(listen_fd, 5);

    fd_set all_set, rset;
    FD_SET(listen_fd, &all_set);
    memset(client_fds, -1, FOPEN_MAX);

    int max_fd = listen_fd;
    char buf[MAX_LEN];
    while(true) {
        rset = all_set;

        int n_ready = select(max_fd, &rset, nullptr, nullptr, nullptr);
        if (n_ready == 0) {
            std::cout << "continue" << std::endl;
            continue;
        }
        if (n_ready < 0) {
            std::cout << "error happend in select" << std::endl;
            break;
        }

        if (FD_ISSET(listen_fd, &rset)) {
            socklen_t client_addr_len = sizeof(client_addr);
            int client_fd = accept(listen_fd, (struct sockaddr*)&client_addr, &client_addr_len);
            bool flag = true;
            for(int i = 0; i < FOPEN_MAX; ++i) {
                if (client_fds[i] == -1) {
                    FD_SET(client_fd, &all_set);
                    client_fds[i] = client_fd;
                    flag = false;
                    break;
                }
            }
            if (flag) {
                std::cout << "too many clients" << std::endl;
            }
            --n_ready;
            if (n_ready == 0) {
                continue;
            }
        }
        int i = 0;
        while (n_ready > 0 and i < FOPEN_MAX) {
            if (client_fds[i] == -1) {
                ++i;
                continue;
            }
            if (FD_ISSET(client_fds[i], &rset)) {
                --n_ready;
                ssize_t n = read(client_fds[i], buf, size_t(MAX_LEN));
                if (n == 0) {
                    std::cout << "RST received..." << std::endl;
                    FD_CLR(client_fds[i], &all_set);
                    client_fds[i] = -1;
                } else if (n < 0) {
                    std::cout << "Error happened..." << std::endl;
                    FD_CLR(client_fds[i], &all_set);
                    client_fds[i] = -1;
                } else {
                    write(client_fds[i], buf, sizeof(buf));
                }
            }
            ++i;
        }
    }

}
