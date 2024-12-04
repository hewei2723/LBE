#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

void SCAN(int track[], int n, int start, int direction) {
    int total_distance = 0;
    int next_track = start;
    int i, j;
    printf("访问顺序: %d", start);
    if (direction == 0) { // 向正方向扫描
        for (i = 0; i < n; i++) {
            if (track[i] >= start) {
                int distance = abs(track[i] - next_track);
                total_distance += distance;
                printf(" -> %d (移动距离: %d)", track[i], distance);
                next_track = track[i];
            }
        }
        for (j = i - 1; j >= 0; j--) {
            if (track[j] < start) {
                int distance = abs(track[j] - next_track);
                total_distance += distance;
                printf(" -> %d (移动距离: %d)", track[j], distance);
                next_track = track[j];
            }
        }
    } else { // 向负方向扫描
        for (i = n - 1; i >= 0; i--) {
            if (track[i] <= start) {
                int distance = abs(track[i] - next_track);
                total_distance += distance;
                printf(" -> %d (移动距离: %d)", track[i], distance);
                next_track = track[i];
            }
        }
        for (j = i + 1; j < n; j++) {
            if (track[j] > start) {
                int distance = abs(track[j] - next_track);
                total_distance += distance;
                printf(" -> %d (移动距离: %d)", track[j], distance);
                next_track = track[j];
            }
        }
    }
    printf("\n平均寻道长度: %.2f\n", (float)total_distance / n);
}

int main() {
    int track[MAX_SIZE];
    int n, start, direction;

    printf("请输入磁盘访问序列的长度: ");
    scanf("%d", &n);

    printf("请输入磁盘访问序列: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &track[i]);
    }

    printf("请输入初始磁道号: ");
    scanf("%d", &start);

    printf("请输入扫描方向（0表示向正方向，1表示向负方向）: ");
    scanf("%d", &direction);

    SCAN(track, n, start, direction);

    return 0;
}

//这段代码定义了一个`SCAN`函数，用于实现基于扫描的磁盘调度算法。在`main`函数中，用户可以输入磁盘访问序列的长度、磁盘访问序列、初始磁道号以及扫描方向。然后，调用`SCAN`函数来计算并输出访问顺序、移动距离和平均寻道长度。