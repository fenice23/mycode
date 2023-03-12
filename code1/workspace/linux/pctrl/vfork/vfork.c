#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
int main()  {
    pid_t pid = vfork();
    if (-1 == pid)  {
        perror("vfork fail");
        exit(errno);
    }
    else if (0 == pid)  {
        sleep(3);
        printf("this is child  process and pid is %d, ppid is %d\n", getpid(), getppid());
    }
    else if (pid > 0)   {
        printf("this is parent process and pid is %d, ppid is %d\n", getpid(), getppid());
    }
    printf("--------------------%d\n", getpid());
    if (0 == pid)   {
        exit(errno);//vfork创建的子进程不能在main函数中使用return退出,
        //因为子进程使用return退出时释放了所有资源,导致父进程运行的时候资源错误进而导致崩溃
    }
    return 0;
}
