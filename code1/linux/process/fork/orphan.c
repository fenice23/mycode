#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <errno.h>
int main()  {
    pid_t pid = fork();
    if (-1 == pid)  {
        perror("fork fail");
    }
    else if (0 == pid)  {
        printf("is child  process and PID is: %d\n", getpid());
    }
    else if (pid > 0)   {
        printf("is parent process and PID is: %d\n", getpid());
        exit(errno);
    }
    else    {
        printf("Err!\n");
    }
    printf("-------------------------------------------------------------------------------------------------%d\n", getpid());
    sleep(10000);
    return 0;
}
