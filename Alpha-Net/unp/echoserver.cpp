//
// Created by root on 12/9/17.
//
/*
 * Echo server. User simple multi-process concurrent model.
 */

#include <monetary.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <iostream>
#include <netinet/in.h>
#include <wait.h>
#include "unp.h"

#define MAX_LEN 1024
#define LISTEN_PORT 8787

void str_echo(int sock_fd);

void echo_server()
{
    int listed_fd, client_fd;
    pid_t child_pid;

    socklen_t client_len;
    struct sockaddr_in server_address, client_addres;

    listed_fd = socket(AF_INET, SOCK_STREAM, 0);

    bzero(&server_address, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = htonl(INADDR_ANY);
    server_address.sin_port = htons(LISTEN_PORT);

    bind(listed_fd, (struct sockaddr*)&server_address, sizeof(server_address));
    listen(listed_fd, 5);

    while (true) {
        client_len = sizeof(client_addres);
        client_fd = accept(listed_fd, (struct sockaddr*)&client_addres, &client_len);
        if ((child_pid = fork()) == 0) {
            close(listed_fd);
            str_echo(client_fd);
            exit(0);
        }
        close(client_fd);
    }
}

void str_echo(int sock_fd)
{
    size_t  n;
    char buf[MAX_LEN];

again:
    while ( (n = read(sock_fd, buf, MAX_LEN)) > 0) {
//        std::cout << buf ;
        writen(sock_fd, buf, n);
    }
    
    // errno == EINTR. read is slow system call, if some signal received, then errno is EINTR
    if (n < 0 && errno == EINTR) {
        goto again;
    } else if(n < 0) {
        std::cerr << "str_echo: read error" << std::endl;
    }
}

void sig_chld(int signo) {
    /*
     * SIGCHLD, child process exit, use waitpid to process zombie child-process
     */
    pid_t pid;
    int stat;
    while ((pid = waitpid(-1, &stat, WNOHANG)) > 0) {
        std::cout << "child " << pid << "terminated" << std::endl;
    }
    return;
}

int main()
{
    signal(SIGCHLD, sig_chld);
    echo_server();
    return 0;
}
