#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>

int main()  {
    int fd = open("./linux", O_RDWR | O_CREAT, 0664);
    if (-1 == fd)   {
        perror("open fail");
        exit(errno);
    }
    printf("%d\n", O_RDWR | O_CREAT);
    printf("fd = %d\n", fd);
    while (1)   {
        sleep(1);
    }
    close(fd);
    fd = -1;
    return 0;
}
