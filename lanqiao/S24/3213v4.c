#include <stdio.h>
#include <math.h>
int n = 0, P, Q,jg;
float N[200],max;
typedef struct {
    int max;
    int index;
} MaxResult;
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