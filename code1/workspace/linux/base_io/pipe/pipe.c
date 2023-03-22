#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <stdlib.h>

int main()  {
    int fd[2] = { 0 };
    int ret = pipe(fd);
    if (ret == -1)  {
        perror("pipe fail");
        exit(errno);
    }
    printf("fd[0] = %d, fd[1] = %d\n", fd[0], fd[1]);
    while (1)   {
        sleep(1);
    }
    return 0;
}
