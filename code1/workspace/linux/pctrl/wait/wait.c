#include <stdio.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <unistd.h>
int main()  {
    pid_t pid = fork();
    if (0 == pid)   {//child
        printf("child \n");
        //sleep(5); 
        exit(errno);
    }
    else if (pid > 0)   {//parent
        printf("parent\n");
        sleep(5);
        wait(NULL);
        while (1)   {
            printf("正在打麻将~~~\n");
            sleep(1);
        }
    }
    else if (-1 == pid) {//fail
        perror("fork fail");
    }
    return 0;
}
