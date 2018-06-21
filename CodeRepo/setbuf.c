#include <stdio.h>

int main() {
    char buf[BUFSIZ];
    setbuf(stdout, buf);
    puts("hello world");
    puts(buf);
    return 0;
}
