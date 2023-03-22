#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <fcntl.h>

int main()  {
    int fd = open("./linux", O_RDWR | O_CREAT, 0664);
    if (-1 == fd)   {
        perror("open fail");
        exit(errno);
    }
    printf("fd = %d\n", fd);
    dup2(fd, 1);
    printf("class out\n");
    close(fd);
    fd = -1;
    return 0;
}
