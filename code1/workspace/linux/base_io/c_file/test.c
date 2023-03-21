#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
int main1()  {
    //FILE* fp = fopen("./linux", "r");
    //FILE* fp = fopen("./linux", "w");
    //FILE* fp = fopen("./linux", "a");
    //FILE* fp = fopen("./linux", "w+");
    FILE* fp = fopen("./linux", "r+");
    if (!fp)    {
        perror("fopen fail");
        exit(errno);
    }
    char buff[1024] = "";
    ssize_t r_ret = fread(buff, 1, sizeof(buff) - 1, fp);
    printf("%s\n", buff);
    printf("r_ret = %ld\n", r_ret);
    //char buff[1024] = "";
    //strcpy(buff, "linux-57");
    //size_t w_ret = fwrite(buff, 1, 8, fp);
    //printf("open success\n");
    //printf("w_ret = %ld\n", w_ret);
    fclose(fp);
    fp = NULL;
    return 0;
}
int main()  {
    FILE* fp = fopen("./linux", "r+");
    if (!fp)    {
        perror("fopen fail");
        exit(errno);
    }
    char buff[1024] = "";
    strcpy(buff, "linux-57");
    ssize_t w_ret = fwrite(buff, 1, strlen(buff) + 1, fp);
    printf("w_ret = %d\n", w_ret);
    memset(buff, '\0', sizeof(buff));
    fseek(fp, 0, SEEK_SET);
    ssize_t r_ret = fread(buff, 1, sizeof(buff) - 1, fp);
    printf("strlen(buff):%d\n", strlen(buff));
    printf("r_ret = %d, buff:%s\n", r_ret, buff);
    printf("open sucess!\n");
    fclose(fp);
    fp = NULL;
    return 0;
}
