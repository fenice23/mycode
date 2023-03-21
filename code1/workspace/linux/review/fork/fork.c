#include <stdio.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>

int main()  {
    pid_t pid = fork();
    if (-1 == pid)  {
        perror("fork fail");
        exit(errno);
    }
    else if (0 == pid)  {
        //child
        printf("i am child , pid=%d, ppid=%d\n", getpid(), getppid());
    }
    else if (pid > 0)   {
        //parent
        printf("i am father, pid=%d, ppid=%d\n", getpid(), getppid());
    }
    while (1)   {
        sleep(1);
    }
    return 0;
}
