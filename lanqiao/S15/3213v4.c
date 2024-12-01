#include <stdio.h>
#include <math.h>

int n = 0, P, Q, jg = 0;
float N[20]; // 用于存储数值的数组

// 获取最大值的索引
int find_max_index() {
    int max_index = 0;
    for (int i = 1; i < n; i++) {
        if (N[i] > N[max_index]) {
            max_index = i;
        }
    }
    return max_index;
}

int main() {
    // 输入 n, P, Q
    scanf("%d %d %d", &n, &P, &Q);

    // 输入 n 个数值到数组 N
    for (int i = 0; i < n; i++) {
        scanf("%f", &N[i]);
    }

    // 找到当前最大值的索引
    int max_index = find_max_index();

    // 先使用 P 次处理
    for (int i = 0; i < P; i++) {
        N[max_index] = sqrt(N[max_index]);  // 求最大值的平方根
        max_index = find_max_index();  // 更新最大值索引
    }

    // 再使用 Q 次处理
    for (int i = 0; i < Q; i++) {
        N[max_index] = N[max_index] / 2;  // 最大值除以 2
        max_index = find_max_index();  // 更新最大值索引
    }

    // 累加数组元素
    for (int i = 0; i < n; i++) {
        jg += N[i];
    }

    // 输出结果
    printf("%d\n", (int)jg);  // 输出结果

    return 0;
}
