#include <stdio.h>
#include <unistd.h>
int main()  {
    char tmp[10] = "";
    for (int i = 0; i < 9; i++) {
        tmp[i] = '-';
        printf("%s\n", tmp);
        //fflush(stdout);
        usleep(1000000);
    }
    return 0;
}
