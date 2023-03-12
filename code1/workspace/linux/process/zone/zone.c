#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
int g_val = 100;
int main()  {
    pid_t pid = fork();
    if (-1 == pid)    {
        perror("fork fail");
        exit(errno);
    }
    else if (0 == pid)  {
        g_val = 200;
        printf("this is child----g_val:%d-%p\n", g_val, &g_val);
    }
    else    {
        sleep(1);
        printf("this is parent---g_val:%d-%p\n", g_val, &g_val);
    }
    return 0;
}
