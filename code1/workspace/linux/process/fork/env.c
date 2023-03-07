#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
int main(int argc, char* argv[], char* env[])  {
    for (int i = 0; i < argc; i++)  {
        printf("argv[%d] = %s\n", i, argv[i]);
    }
    //while (*env++)  puts(*env);
    //const char* Env = "MYVAL";
    //char* e = getenv(Env);
    //if (e)
    //    printf("%s\n", e);
    //else
    //    printf("%s is not exist!\n", Env);
    //for (;;)    sleep(1);
    //extern char** environ;
    //for (int i = 0; environ[i]; i++)  {
    //    puts(environ[i]);
    //}
    //while (*environ++)  {
    //    puts(*environ);
    //}
    return 0;
}
