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
        }
        else
        {
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
                if (i % 2 == 0 && n[i] % 2 == 0 && i+1 % 2 != 0 && n[i+1] % 2 != 0)
                {
                    sum++;
                }
            }
        }
    }
    printf("%d", sum);
}
=======

// 函数：判断一个数是否为“好数”
int isGoodNumber(int num) {
    int position = 1; // 从个位开始，位置从 1 开始
    while (num > 0) {
        int digit = num % 10;
        if (position % 2 == 1) { // 奇数位
            if (digit % 2 == 0) {
                return 0; // 不满足条件
            }
        } else { // 偶数位
            if (digit % 2 != 0) {
                return 0; // 不满足条件
            }
        }
        num /= 10;
        position++;
    }
    return 1; // 满足所有位的条件
}

int main() {
    int N;
    scanf("%d", &N);
    
    int count = 0;
    for (int num = 1; num <= N; num++) {
        if (isGoodNumber(num)) {
            count++;
        }
    }
    
    printf("%d", count);
    return 0;
}
>>>>>>> fe2b4c9a2025de515b12ec0f3e2365ab7bd43e09
