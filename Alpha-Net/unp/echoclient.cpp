//
// Created by root on 12/9/17.
//

#include <cstdio>
#include <unistd.h>
#include <cstring>
#include <iostream>
#include <netinet/in.h>
#include <arpa/inet.h>

#include "unp.h"

#define MAX_LEN 1024
#define SERVER_PORT 8787

void str_cli(FILE *fp, int sock_fd);

void echo_client(int argc, char **argv)
{
    int sock_fd;
    struct sockaddr_in server_addr, client_addr;
//    if (argc != 2) {
//        std::cerr << "usage: echoclient <ip address>" << std::endl;
//        exit(0);
//    }

    sock_fd = socket(AF_INET, SOCK_STREAM, 0);
    bzero(&server_addr, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT);
    inet_pton(AF_INET, "127.0.0.1", &server_addr.sin_addr);

    connect(sock_fd, (struct sockaddr*)&server_addr, sizeof(server_addr));
    str_cli(stdin, sock_fd);
    exit(0);
}

void str_cli(FILE *fp, int sock_fd)
{
    char send_line[1024], rcv_line[1024];
    while( fgets(send_line, MAX_LEN, fp) != nullptr) {
        write(sock_fd, send_line, strlen(send_line));
        if (readline(sock_fd, rcv_line, MAX_LEN) == 0) {
            std::cerr << "str_cli: server terminated prematurely" << std::endl;
        }
        fputs(rcv_line, stdout);
    }
}

int main(int argc, char **argv)
{
    echo_client(argc, argv);
    return 0;
}
