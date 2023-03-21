#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
int main()  {
    printf("hhhhhhhhhhhhhhhhh\n");
    //execl("/bin/ls", "ls", "-l", "-a", "-h", NULL);
    execl("/bin/pwd", "pwd", NULL);
    while (1)   {
        printf("linux!\n");
        sleep(1);
    }
    return 0;
}
