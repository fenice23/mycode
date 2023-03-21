#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
int g = 6;
int main(int argc, char* argv[], char* env[])  {
    for (int i = 0; i < argc; i++)  {
        printf("argv[%d] <===> [%s]\n", i, argv[i]);
    }
    for (int i = 0; env[i]; i++)    {
        printf("env[%d] <===> [%s]\n", i, env[i]);
    }
    int var = 88;
    //pid_t pid = vfork();
    //if (pid < 0)    {
    //    perror("vfork fail");
    //}
    pid_t pid = fork();
    if (pid < 0)    {
        perror("fork fail");
    }
    else if (0 == pid)  {
        g++;
        var++;
        exit(errno);
        //return errno;
    }
    else if (pid > 0)   {
        printf("g = %d, var = %d\n", g, var);
        exit(errno);
    }
    return 0;
}
