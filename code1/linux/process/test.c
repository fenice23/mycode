#include <stdio.h>
#include <unistd.h>

int main()  {
    int a = 0;
    while (++a) sleep(1);
    return 0;
}
