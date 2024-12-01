#include <stdio.h>
int lcm(int a, int b, int c)
{
    int i = 1;
    while (i < a * b * c)
    {

        if ((i % a == 0) && (i % b == 0) && (i % c == 0))
        {
            return i;
        }
        else
        {
            i++;
        }
    }
}
int main()
{
    int a, b, c, n, s, i = 0, num = 0, max, max_num;
    int H[2000], S[2000][2];
    // s=(a*b*c)*lcm(a,b,c)/(lcm(a,b,1)*lcm(b,c,1)*lcm(c,a,1));
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &H[i]);
    }
    for (int i = 0; i < n - 2; i++)
    { // 第一重循环，选择第一个宝石
        for (int j = i + 1; j < n - 1; j++)
        { // 第二重循环，选择不同的第二个宝石
            for (int k = j + 1; k < n; k++)
            { // 第三重循环，选择不同的第三个宝石
                int a = H[i];
                int b = H[j];
                int c = H[k];
                S[num][0] = (a * b * c * lcm(a, b, c)) / (lcm(a, b, 1) * lcm(b, c, 1) * lcm(c, a, 1));
                S[num][1] = a * 100 + b * 10 + c; 
                num++;
            }
        }
    }

    max = S[0][0]; // 假设第一个元素是最大值
    for (int i = 1; i < n; i++)
    {
        if (S[i][0] > max)
        {
            max = S[i][0]; // 更新最大值
            max_num = i;
        }
    }
    printf("%d %d %d", S[max_num][1]/100,S[max_num][1]/10%10,S[max_num][1]%10);
}