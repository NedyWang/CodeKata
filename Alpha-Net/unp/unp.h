//
// Created by root on 12/9/17.
//

#ifndef LEET_CODE_UNP_H
#define LEET_CODE_UNP_H

#include <unistd.h>

ssize_t readn(int fd, void *buff, size_t nbytes);
ssize_t readline(int fd, void *buff, size_t maxlen);
ssize_t writen(int fd, const void *buff, size_t nbytes);

#endif //LEET_CODE_UNP_H
