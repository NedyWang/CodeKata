//
// Created by root on 12/7/17.
//
#include <sys/socket.h>
#include <netinet/in.h>
#include <cstring>
#include <poll.h>
#include <cstdio>

#define PORT 8787
#define MAX_LEN 1024

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

    struct pollfd poll_set[FOPEN_MAX];
    poll_set[0].fd = listen_fd;
    poll_set[0].events = POLLRDNORM;

    int numbers = 1;

    while (true) {
        int n_ready = poll(poll_set, numbers, -1);

        if (n_ready > 0) {
            if (poll_set[0].revents == POLLIN) {

            }

        }

    }
}
