#include <stdio.h>
#include <math.h>

int n = 0, P, Q,jg;
float N[20];  // jg 改为 float 类型以保存精确结果

// 快速排序函数
void quicksort(float arr[], int left, int right) {
    if (left >= right) return;

    float pivot = arr[left];  // 选择第一个元素作为基准
    int i = left, j = right;

    while (i < j) {
        // 从右往左找到第一个小于基准的元素
        while (i < j && arr[j] <= pivot) j--;
        if (i < j) arr[i++] = arr[j];  // 把小的移到左边

        // 从左往右找到第一个大于基准的元素
        while (i < j && arr[i] >= pivot) i++;
        if (i < j) arr[j--] = arr[i];  // 把大的移到右边
    }

    arr[i] = pivot;  // 把基准放回最终位置

    // 递归排序左右两部分
    quicksort(arr, left, i - 1);
    quicksort(arr, i + 1, right);
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
        quicksort(N, 0, n - 1);  // 使用快速排序
        N[0] = sqrt(N[0]);  // 求最大值的平方根
    }

    // 再使用 Q 次处理
    for (int i = 0; i < Q; i++)
    {
        quicksort(N, 0, n - 1);  // 使用快速排序
        N[0] = N[0] / 2;  // 最大值除以 2
    }

    // 累加数组元素
    for (int i = 0; i < n; i++)
    {
        jg += N[i];
    }

    // 输出结果
    printf("%d\n", jg);  // 输出结果保留两位小数

    return 0;
}
