#include <stdio.h>
#include <math.h>
int length(int n)
{
    return (int)log10(n) + 1;
}
int main()
{
    int n[7], num = 123, b;
            int add = 0;
    // scanf("%d",&num);
    int a = length(num);        // a为总长
    for (int i = 0; i < a; i++) // 循环a次
    {
        int b = length(num) - 1;
        int c = pow(10, b);
        n[i] = num / c;
        num = num % c;
    }
    for (int i = 0; i < a; i++)
    {
        if (i + 1 % 2 == 0) // 如果是偶数位
        {
            if (n[i] % 2 == 0)
            {
                add++;
            }
        }
        else
        {
            if (n[i] % 2 != 0)
            {
                add++;
            }
        }
    }
    printf("%d",add);
}