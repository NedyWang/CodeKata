//
// Created by root on 12/9/17.
//


#include <zconf.h>
#include <netinet/in.h>
#include <cstring>
#include <iostream>
#include <arpa/inet.h>

#define MAX_LEN 1024
#define PORT 13

void daytimeServer()
{
    int listen_fd, conn_fd;
    socklen_t socklen;
    struct sockaddr_in server_addr, client_addr;

    char buf[MAX_LEN];
    time_t tickets;

    listen_fd = socket(AF_INET, SOCK_STREAM, 0);

    bzero(&server_addr, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    server_addr.sin_port = htons(PORT);

    bind(listen_fd, (struct sockaddr*)&server_addr, sizeof(server_addr));
    listen(listen_fd, 5);

    while(true) {
        socklen = sizeof(client_addr);
        conn_fd = accept(listen_fd, (struct sockaddr*)&client_addr, &socklen);
        std::cout << "connection from "
                  << inet_ntop(AF_INET, &client_addr.sin_addr, buf, sizeof(buf))
                  << " : "
                  << ntohs(client_addr.sin_port)
                  << std::endl;
        tickets = time(nullptr);
        snprintf(buf, sizeof(buf), "%.24s\r\n", ctime(&tickets));
        write(conn_fd, buf, sizeof(buf));
        close(conn_fd);
    }
}

int main()
{
    daytimeServer();
}
