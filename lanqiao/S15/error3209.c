#include <stdio.h>
<<<<<<< HEAD
#include <math.h>
int n[7];
int length(int n) // 获取长度
{
    return (int)log10(n) + 1;
}
int de(int num) // 获取每一位数字
{
    int a = length(num);
    for (int i = a; i > 0; i--) // 循环a次
    {
        int b = length(num) - 1;
        int c = pow(10, b);
        if (num == 0)
        {
            n[1] = 0;
=======
int main()
{
    int n=1, num,a=0;
    scanf("%d",&num);
    while (a < num)
    {
        if (n < 5)
        {
            a=2*n-1;
>>>>>>> fe2b4c9a2025de515b12ec0f3e2365ab7bd43e09
        }
        else if (n >= 5)
        {
<<<<<<< HEAD
            n[i] = num / c;
            num = num % c;
        }
    }
}
int main()
{
    int num = 24, sum = 0;
    for (int other = 1; other < num; other++)
    {
        de(other); // 获取每一位数字
        int a = length(other);
        for (int i = 1; i < a + 1; i++)
        {
            if (other < 10)
            {

                if (i % 2 == 0 && n[i] % 2 == 0)
                {
                    sum++;
                }
                else if (i % 2 != 0 && n[i] % 2 != 0) //
                {
                    sum++;
                }
            }
            else
            {
            }
        }
    }
    printf("%d", sum);
}
=======
            a=2*n+11;
        }    
        n++;   
    }
    printf("%d",n);
}
>>>>>>> fe2b4c9a2025de515b12ec0f3e2365ab7bd43e09
