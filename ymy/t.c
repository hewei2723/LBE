/*
小明这天在参加公司团建，团建项目是爬山。在 x 轴上从左到右一共有 n座山，
第 i 座山的高度为 hi。他们需要从左到右依次爬过所有的山，需要花费的体力值为 S = Σni=1hi。
然而小明偷偷学了魔法，可以降低一些山的高度。
他掌握两种魔法，第一种魔法可以将高度为 H 的山的高度变为 ⌊√H⌋，可以使用 P 次；
第二种魔法可以将高度为 H 的山的高度变为 ⌊H/2⌋，可以使用 Q 次。
并且对于每座山可以按任意顺序多次释放这两种魔法。
小明想合理规划在哪些山使用魔法，使得爬山花费的体力值最少。请问最优情况下需要花费的体力值是多少？
*/
#include <stdio.h>
#include <math.h>
int i, n, P, Q, s = 0;
int j, temp;
int main()
{
    scanf("%d %d %d", &n, &P, &Q);
    int hi[n];
    for (i = 0; i <= n - 1; i++)
    {
        scanf("%d", &hi[i]);
    }
    for (i = 0; i < P; i++)
    {
        for (i = 0; i < n; i++)
        {
            for (j = i + 1; j < n - i; j++)
            {
                if (hi[i] < hi[j])
                {
                    temp = hi[j];
                    hi[j] = hi[i];
                    hi[i] = temp;
                }
            }
        }
        hi[0] = sqrt(hi[0]);
    }
    for (int i = 0; i < Q;i++)
    {
        for (i = 0; i < n; i++)
        {
            for (j = i + 1; j < n - i; j++)
            {
                if (hi[i] < hi[j])
                {
                    temp = hi[j];
                    hi[j] = hi[i];
                    hi[i] = temp;
                }
            }
        }
        hi[0] = hi[0] / 2;
    }
    for (size_t i = 0; i < n; i++)
    {
        s = s + hi[i];
    }
    printf("%d", s);
}
