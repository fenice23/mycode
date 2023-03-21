#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
int main()  {
    int * p = (int*)malloc(10 * sizeof(int));
    free(p + 1);
    int r = wait(NULL);
    if (r == -1)    {
        perror("wait fail");
    }
    //for (int i = 0; i < 256; i++)   {
    //    printf("errmsg: %s\n", strerror(i));
    //}
    pid_t pid = fork();
    if (-1 == pid)  {
        perror("fork fail");
        exit(errno);
    }
    else if (0 == pid)  {//child
        sleep(5);
        exit(99);
    }
    else if (pid > 0)   {//parent
        int status = 0;
        int ret = 0;
        while ((ret = waitpid(pid, &status, WNOHANG)) == 0) {
            sleep(1);
            printf("抽根烟~~~\n");
        }
        if (ret == -1)  {
            printf("没有子进程,或者这个pid对应的子进程不存在!\n");
        }
        else if (ret == 0)  {
            printf("子进程没有退出\n");
        }
        else if (ret > 0)   {
            printf("父进程成功等待退出的子进程,退出的子进程pid is %d\n", ret);
            if (WIFEXITED(status))  {
                printf("child normal exit, and exit code is %d\n", WEXITSTATUS(status));
            }
            else    {
                printf("child is not normal exit, and signal is %d\n", status & 0x7f);
            }
            //int res1 = status & 0X0000007F;
            //int res2 = ((status >> 8) & 0X000000FF);
            //if (res1 == 0)   {
            //    printf("child normal exit, and exit code is %d\n", res2);
            //}
            //else    {
            //    printf("child is not normal exit, and signal is %d\n", res1);
            //}
            //printf("子进程退出返回值%d\n", status);
        }
        while (1)   {
            sleep(1);
            printf("打麻将~~~\n");
        }
        //int ret = waitpid(pid, NULL, WNOHANG);
        //if (ret == 0)   {
        //    printf("没有子进程退出\n");
        //}
        //else if (ret == -1) {
        //    printf("没有子进程!\n");
        //}
        //else if (ret > 0)   {
        //    printf("成功等待子进程!\n");
        //}
        //while (1)   {
        //    printf("正在打麻将~~~\n");
        //    sleep(1);
        //}
    }
    return 0;
}
