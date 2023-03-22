#include <stdio.h>

void func(int* fd)  {
    *fd = 10;
}

void func1(int fd)  {
    printf("%d\n", fd);
}

int main()  {
    int fd;
    func(&fd);
    func1(fd);
    printf("%d\n", fd);
    return 0;
}
