#include <stdio.h>
#include <time.h>

#define MAX 99997

clock_t start, stop;
double duration;

void *basic_memset(void *s, int c, size_t n)
{
    size_t cnt = 0;
    unsigned char *schar = s;
    while (cnt < n){
        *schar++ = (unsigned char)c;
        cnt++;
    }
    return s;
}

int main(int argc, char *argv[])
{
    int i = 0;
    char a[MAX];
    start = clock();
    for (; i < 50000; i++){
        memset(a, 0, sizeof(a));// MAX取99997
    }
    stop = clock();
    duration = (double)(stop - start) / CLK_TCK;
    printf("%f\n", duration);
    return 0;
}