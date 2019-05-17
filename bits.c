#include <stdio.h>

int main()
{
    int a = 0x000f;
    a = a | 1 << 13;
    a = a | 1 << 5;
    for (int i = 15; i >= 0; i--)
    {
        int n = a >> i;
        printf((n & 1) ? "1" : "0");
    }
    printf("\n0%x", a);
    return 0;
}