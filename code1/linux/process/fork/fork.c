#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
int main()  {
    printf("hello!\n");
    printf("hello!\n");
    printf("hello!\n");
    printf("====================================\n");
    pid_t id = fork();
    if (-1 == id)   {
        printf("fork child process fail!\n");
    }
    else if (id > 0)    {
        printf("%d\n", id);
        printf("is parent process, id: %d\n", getpid());
    }
    else if (id == 0)   {
        printf("is child process,  id: %d\n", getpid());
        exit(errno);
    }
    else    {
        printf("Err!\n");
    }
    printf("this is process!\n");
    sleep(100);
    return 0;
}
//int main()  {
//    pid_t id = fork();
//    printf("this is a process!\n");
//    return 0;
//}
