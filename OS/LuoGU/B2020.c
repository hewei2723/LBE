#include <stdio.h>
int main()
{
    int a[5] = {};
    int b=0; // 用来存储余数，剩下的苹果
    scanf("%d %d %d %d %d", &a[0], &a[1], &a[2], &a[3], &a[4]);
    for (int i = 0; i < 5; i++)
    {
        if (i == 0)
        {
            a[4] = a[4] + a[0] / 3;
            a[1] = a[1] + a[0] / 3;
            b= a[0] % 3;
        }
        else
        {
            a[i + 1] = a[i + 1] + a[i] / 3;
            a[i - 1] = a[i - 1] + a[i] / 3;
            b=b+ a[i] % 3;
            a[i] = a[i] / 3;
        }
    }
    for (int i = 0; i < 5; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n%d",b);   
}