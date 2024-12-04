#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

void FCFS(int track[], int n, int start) {
    int total_distance = 0;
    int next_track = start;
    printf("访问顺序: %d", start);
    for (int i = 0; i < n; i++) {
        int distance = abs(track[i] - next_track);
        total_distance += distance;
        printf(" -> %d (移动距离: %d)", track[i], distance);
        next_track = track[i];
    }
    printf("\n平均寻道长度: %.2f\n", (float)total_distance / n);
}

int main() {
    int track[MAX_SIZE];
    int n, start;

    printf("请输入磁盘访问序列的长度: ");
    scanf("%d", &n);

    printf("请输入磁盘访问序列: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &track[i]);
    }

    printf("请输入初始磁道号: ");
    scanf("%d", &start);

    FCFS(track, n, start);

    return 0;
}

//这段代码在`FCFS`函数中添加了一个`distance`变量，用于记录当前磁道号与下一次要访问的磁盘号之间的距离。在每次循环中，计算当前磁道号与下一次要访问的磁盘号之间的距离，并输出下一次要访问的磁盘号和移动的距离。