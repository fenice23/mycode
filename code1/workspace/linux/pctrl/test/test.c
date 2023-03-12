#include <stdio.h>
#include <errno.h>
#include <unistd.h>
#include <stdlib.h>

void function() {
    printf("^^^^^^^");
    //return;
    exit(errno);
    //_exit(errno);
    printf("#######\n");
}

int main()  {
    char tmp[11] = "";
    for (int i = 0; i < 10; i++)    {
        tmp[i] = '-';
        printf("%s", tmp);
        fflush(stdout);
        usleep(1000000);
    }
    printf("-------\n");
    function();
    printf("*******\n");
}
