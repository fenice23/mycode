#include <stdio.h>
#include <unistd.h>
#include "b.h"

int main()  {
    for (int i = 0; i < 10; i++)    {
    //  sleep(3);
        print_child();
    }
    return 0;
}
