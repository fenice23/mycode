#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>

int main()  {
    int fd = open("./linux", O_RDWR | O_CREAT, 0664);
    if (-1 == fd)   {
        perror("open fail");
        exit(errno);
    }
    printf("fd = %d\n",fd);
    dup2(fd, 1);
    printf("dup2 is easy!\n");
    close(fd);
    fd = -1;
    return 0;
}
