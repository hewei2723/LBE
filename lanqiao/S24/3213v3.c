#include <stdio.h>
#include <math.h>

int n = 0, P, Q,jg;
float N[20];

// 堆调整函数
void heapify(float arr[], int n, int i) {
    int largest = i;       // 假设当前节点是最大节点
    int left = 2 * i + 1;  // 左子节点
    int right = 2 * i + 2; // 右子节点

    // 如果左子节点大于根节点
    if (left < n && arr[left] > arr[largest])
        largest = left;

    // 如果右子节点大于最大节点
    if (right < n && arr[right] > arr[largest])
        largest = right;

    // 如果最大值不是根节点，则交换并继续调整
    if (largest != i) {
        float temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;

        heapify(arr, n, largest);  // 递归调整子树
    }
}

// 堆排序
void heapSort(float arr[], int n) {
    // 构建最大堆
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // 逐一从堆中取出最大元素
    for (int i = n - 1; i > 0; i--) {
        // 将当前最大元素（堆顶）交换到数组末尾
        float temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        // 调整剩余的堆
        heapify(arr, i, 0);
    }
}

int main() {
    // 输入 n, P, Q
    scanf("%d %d %d", &n, &P, &Q);

    // 输入 n 个数值到数组 N
    for (int i = 0; i < n; i++) {
        scanf("%f", &N[i]);
    }

    // 先使用 P 次处理
    for (int i = 0; i < P; i++) {
        heapSort(N, n);  // 使用堆排序
        N[0] = sqrt(N[0]);  // 求最大值的平方根
    }

    // 再使用 Q 次处理
    for (int i = 0; i < Q; i++) {
        heapSort(N, n);  // 使用堆排序
        N[0] = N[0] / 2;  // 最大值除以 2
    }

    // 累加数组元素
    for (int i = 0; i < n; i++) {
        jg += N[i];
    }

    // 输出结果
    printf("%d\n", jg);  // 输出结果保留两位小数

    return 0;
}
