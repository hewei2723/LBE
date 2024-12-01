#include <stdio.h>
#include <math.h>

int n = 0, P, Q;
float N[20]; // 用于存储数值的数组

// 找到数组中的最大值索引
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
    int jg; // 结果变量
    int max_index;

    // 输入 n, P, Q
    scanf("%d %d %d", &n, &P, &Q);

    // 输入 n 个数值到数组 N
    for (int i = 0; i < n; i++) {
        scanf("%f", &N[i]);
    }

    // 先使用 P 次处理
    for (int i = 0; i < P; i++) {
        max_index = find_max_index();    // 找到最大值索引
        N[max_index] = sqrt(N[max_index]); // 对最大值取平方根
    }

    // 再使用 Q 次处理
    for (int i = 0; i < Q; i++) {
        max_index = find_max_index();   // 找到最大值索引
        N[max_index] = N[max_index] / 2;  // 对最大值除以2
    }

    // 累加数组元素
    for (int i = 0; i < n; i++) {
        jg += N[i];
    }

    // 输出结果
    printf("%d\n", jg);  // 输出累加结果，保留整数部分

    return 0;
}
