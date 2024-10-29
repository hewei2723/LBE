/*
小明这天在参加公司团建，团建项目是爬山。在 x 轴上从左到右一共有 n座山，第 i 座山的高度为 hi。
他们需要从左到右依次爬过所有的山，需要花费的体力值为 S = Σni=1hi。
然而小明偷偷学了魔法，可以降低一些山的高度。他掌握两种魔法，第一种魔法可以将高度为 H 的山的高度变为 ⌊√H⌋，
可以使用 P 次；第二种魔法可以将高度为 H 的山的高度变为 ⌊H/2⌋，可以使用 Q 次。并且对于每座山可以按任意顺序多次释放这两种魔法。
小明想合理规划在哪些山使用魔法，使得爬山花费的体力值最少。请问最优情况下需要花费的体力值是多少？

//高度就是体力值
//魔法P将高度降低为根号2倍
//魔法Q将高度降为原来的一半
//输入第一行为n座山 P次 Q次
//第二行为，每座山的高度
根号收敛快大数用根号小数用除法
*/
/*
如果只有两座山 n=2 第一座山高4 第二座山高16 P使用一次根号2 Q一次除以2
n1/2+根号n2=2+4=6
如果只有三座山 n=3 第一座山高4 第二座山高16 第三座山高9 P使用一次根号2 Q一次除以2
4+9+2 15
*/
// 找到最大的P个数，对其使用P，直到P用完，剩下的按最大的使用Q
#include <stdio.h>
#include <math.h>

int n = 0, P, Q;
long long jg;
int heights[10000];

typedef struct {
    int max;
    int index;
} MaxResult;

MaxResult findMax() {
    MaxResult result = {heights[0], 0};
    for (int i = 1; i < n; i++) {
        if (heights[i] > result.max) {
            result.max = heights[i];
            result.index = i;
        }
    }
    return result;
}

int main() {
    scanf("%d %d %d", &n, &P, &Q);
    for (int i = 0; i < n; i++) {
        scanf("%d", &heights[i]);
    }

    for (int i = 0; i < P; i++) {
        MaxResult result = findMax();
        heights[result.index] = (int)sqrt(result.max);
    }
    
    for (int i = 0; i < Q; i++) {
        MaxResult result = findMax();
        heights[result.index] = result.max / 2;
    }

    for (int i = 0; i < n; i++) {
        jg += heights[i];
    }

    printf("%lld\n", jg);
    return 0;
}
