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
int n = 0, P, Q,jg;
float N[20],max; // jg 改为 float 类型以保存精确结果
// 选择排序函数，用于从大到小排序
typedef struct {
    int max;
    int index;
} MaxResult;
void paixv()
{
    int big;
    float temp;
    for (int i = 0; i < n - 1; i++)
    {
        big = i;
        // 找到未排序部分的最大元素
        for (int j = i + 1; j < n; j++)
        {
            if (N[j] > N[big])
            {
                big = j; // 更新最大元素的位置
            }
        }
        // 如果找到的最大元素不是当前的元素，交换两者
        if (big != i)
        {
            temp = N[i];
            N[i] = N[big];
            N[big] = temp;
        }
    }
}
/*void paiv(){
    //每次只找到最大的就可以了
    //将每个数的长度转换为内存空间，并将最后一个字节设置标志，从第一个数开始，覆盖内存空间，循环完成后查看最后一个字节是谁的标志，谁就是最大的
    int pmax,pbig;//最大值pmax比较值pbig
    return max;
    
}
*/
MaxResult findMax() {
    int pmax = N[0]; 
    MaxResult result;
    for (int i = 1; i < n; i++) {
        if (N[i] > pmax) {
            pmax = N[i];
            result.max=pmax;// 更新最大值
            result.index=i; // 记录最大值的位置
        }
    }
    return result; // 返回最大值
}

int main()
{
    // 输入 n, P, Q
    scanf("%d %d %d", &n, &P, &Q);

    // 输入 n 个数值到数组 N
    for (int i = 0; i < n; i++)
    {
        scanf("%f", &N[i]);  // 改为 %f 来读取浮点数
    }
    // 先使用 P 次处理
    for (int i = 0; i < P; i++)
    {
        MaxResult result = findMax();  // 排序
        N[result.index] = sqrt(result.max);  // 求最大值的平方根
    }
    // 再使用 Q 次处理
    for (int i = 0; i < Q; i++)
    {
        MaxResult result = findMax();  // 排序
        N[result.index] = result.max / 2;  // 最大值除以 2N[0] / 2;  // 最大值除以 2
    }
    // 累加数组元素
    for (int i = 0; i < n; i++)
    {
        jg += N[i];
    }
    // 输出结果
    printf("%d\n", jg);
    return 0;
}