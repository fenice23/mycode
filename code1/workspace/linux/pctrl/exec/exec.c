#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[], char* env[])  {
    //for (int i = 0; i < argc; i++)  {
    //    printf("argv[%d] <===> %s\n", i, argv[i]);
    //}
    pid_t pid = fork();
    if (0 == pid)   {//child
        char* child_argv[] = { "a", "-l", "-p", "zhang", NULL };
        //execl("./a", NULL, NULL);
        //execl("./a", "a", "-l", "-p", "zhang", NULL);
        //execv("/home/tzh/Desktop/workspace/linux/pctrl/exec/a", child_argv);
        //execv("./a", child_argv);
        execl("a", "ls", "-l", "-a", "-h", NULL);
    }
    else if (-1 == pid) {//fail
        perror("fork fail");
    }
    else if (pid > 0)   {//parent

    }
    printf("-------------------%d\n", getpid());
    return 0;
}
