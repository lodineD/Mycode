#include <stdio.h>
#include <time.h>

#define MAX 99997

clock_t start, stop;
double duration;

void *basic_memset(void *s, int c, size_t n)
{
    size_t cnt = 0;
    char *tmps;
    int tmp;
    tmps = (char *)s;

    // 判断源地址是否按4字节对齐，判断二进制位最后两位是否为0。若为0，则地址之间的字节数一定是4的倍数，
    // 一定是按4字节对齐
    if ((unsigned long)tmps & 0x3){
        // 4字节已经对齐，无需优化
        while (cnt < n){
            *tmps++ = (unsigned char)c;
            cnt++;
        }
    }
    // 不是4字节对齐需要处理余数
    else{
        size_t num;
        size_t sl;
        // 求出一共需要cpu的访问次数和剩下的字节余数，用于后续的拆分循环，提高效率
        num = n / 4;
        sl = n % 4;
        // 这里是让cpu直接访问4个字节的tmp，由于int也属于4个字节
        c = c & 0xff; //取低8位，后续直接利用移位，一次tmp就相当于执行了4次tmp
        tmp = c + (c << 8) + (c << 16) + (c << 24);
        while (num--){
            *(int *)tmps = tmp;
            // 地址也应该有变化
            tmps += 4;
        }
        //最后处理余数，一个一个赋值
        while (sl--){
            *tmps++ = (char)c;
        }
    }
    return s;
}

int main(int argc, char *argv[])
{
    int i = 0;
    char a[MAX];
    start = clock();
    for (; i < 50000; i++){
        basic_memset(a, 0, sizeof(a)); // MAX取99997
    }
    stop = clock();
    duration = (double)(stop - start) / CLK_TCK;
    printf("%f\n", duration);
    return 0;
}