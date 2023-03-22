#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
int main()  {
    int count = 0;
    while (1)   {
        int fd = open("./linux", O_RDWR | O_CREAT, 0664);
        if (-1 == fd)   {
            perror("open fail");
            //exit(errno);
            break;
        }
        count++;
        printf("fd = %d\n", fd);
    }
    printf("count = %d\n", count);
    return 0;
}
