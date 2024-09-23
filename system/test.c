#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
    char *str;
    int a = sizeof(int);
    printf("%d", a);
    memset(str, 0, sizeof(str));
    return 0;
}