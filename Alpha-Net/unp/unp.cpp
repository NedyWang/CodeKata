//
// Created by root on 12/9/17.
//

#include <errno.h>
#include "unp.h"

ssize_t readn(int fd, void *buff, size_t nbytes)
{
    size_t nleft = nbytes;
    size_t nread;
    char *ptr = (char *) buff;

    while (nleft > 0) {
        if ((nread = read(fd, ptr, nleft)) < 0) {
            if (errno == EINTR) {
                nread = 0;
            } else {
                return -1;
            }
        } else if (nread == 0) {
            break; //EOF
        }
        nleft -= nread;
        ptr += nread;
    }
    return nbytes - nleft;
}

ssize_t writen(int fd, const void *buf, size_t nbytes)
{
    size_t nleft = nbytes;
    ssize_t nwritten;
    const char* ptr= (char *)buf;

    while(nleft > 0) {
        if ((nwritten = write(fd, ptr, nleft)) <= 0) {
            if (nwritten < 0 && errno == EINTR) {
                nwritten = 0; //and call write again
            }
            else {
                return -1; //error
            }
        }
        nleft -= nwritten;
        ptr += nwritten;
    }
    return nbytes;
}

ssize_t readline(int fd, void *buf, size_t maxlen)
{
    size_t rc, n;
    char c, *ptr;
    ptr = (char *) buf;

    for (n = 0; n < maxlen; ++n) {
        again:
        if ((rc = read(fd, &c, 1)) == 1) {
            *ptr++ = c;
            if (c == '\n') {
                break;
            }
        } else if (rc == 0) {
            *ptr = 0;
            return n - 1;
        } else {
            if (errno == EINTR) {
                goto again;
            }
            return -1;
        }
    }
    *ptr = '\0';
    return n;
}
