#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

//int main()  {
//    int fd = open("./linux", O_RDWR | O_CREAT, 0664);
//    //int fd = open("./linux", 0X42, 0664);//ok
//    if (fd == -1) {
//        perror("open fail");
//        exit(errno);
//    }
//    printf("%d\n", O_RDWR | O_CREAT);
//    printf("fd = %d\n", fd);
//    return 0;
//}

int main()  {
    int fd = open("./linux", O_RDWR | O_CREAT, 0664);
    if (-1 == fd)   {
        perror("open fail");
        exit(errno);
    }
    printf("fd = %d\n", fd);
    char buff[1024] = "";
    strcpy(buff, "linux-57");
    ssize_t w_ret = write(fd, buff, strlen(buff) + 1);
    memset(buff, '\0', sizeof(buff));
    lseek(fd, 0, SEEK_SET);
    ssize_t r_ret = read(fd, buff, sizeof(buff) - 1);
    printf("w_ret = %ld, r_ret = %ld\n", w_ret, r_ret);
    printf("buff:%s\n", buff);
    close(fd);
    fd = -1;
    return 0;
}
