//
// Created by root on 12/22/17.
//

#include <unistd.h>
#include <fcntl.h>
#include <string>

int main()
{
    daemon(1, 0);
    int i = 0;
    const std::string name("/root/workspace/open_source/libevent/libevent/cmake-build-debug/bin/event.fifo");
    int fd = open(name.c_str(), O_WRONLY, 0);
    while ( i++ < 18) {
        sleep(2);
        char buf[20] = "index is ";
        snprintf(buf, 10, "%d\0", i);
        write(fd, buf, sizeof(buf));
    }
    close(fd);
    return 0;
}
