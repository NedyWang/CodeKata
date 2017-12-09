//
// Created by root on 12/9/17.
//
/*
 * This is a very simple daytime client
 */

#include <netinet/in.h>
#include <iostream>
#include <cstring>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_LEN 1024
#define SERVER_PORT 13

int main(int argc, char **argv)
{
    int sock_fd, n;
    char recv_line[MAX_LEN + 1];

    struct sockaddr_in server_address;

    if (argc != 2) {
        std::cerr << "usage: daytimeclient <ip address>" << std::endl;
        return 0;
    }

    if ((sock_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        std::cerr << "socket error" << std::endl;
        return 0;
    }

    bzero(&server_address, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(SERVER_PORT);
    if (inet_pton(AF_INET, argv[1], &server_address.sin_addr) <= 0) {
        std::cerr << "inet_pton error" << std::endl;
        return 0;
    }

    if (connect(sock_fd, (struct sockaddr*)&server_address, sizeof(server_address)) < 0) {
        std::cerr << "connect to server error" << std::endl;
        return 0;
    }

    while ((n = read(sock_fd, recv_line, MAX_LEN)) > 0) {
        recv_line[n] = '\0';
        if (fputs(recv_line, stdout) == EOF) {
            std::cerr << "fputs error" << std::endl;
        }
    }
    if (n < 0) {
        std::cerr << "read error" << std::endl;
    }
    return 0;
}
