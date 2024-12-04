#include <stdio.h>
#include <stdlib.h>

void lruPageReplacement(int pages[], int n, int frames) {
    int frame_list[frames];  // 存储当前物理块中的页面
    int last_used[frames];    // 存储每个页面的最近使用时间（使用序号）
    int page_faults = 0;      // 缺页次数
    int i, j;

    // 初始化物理块和最近使用时间
    for (i = 0; i < frames; i++) {
        frame_list[i] = -1;
        last_used[i] = -1;
    }

    printf("页面访问序列: ");
    for (i = 0; i < n; i++) {
        printf("%d ", pages[i]);
    }
    printf("\n物理块数: %d\n", frames);
    printf("------------------------------------------\n");

    // 遍历每个页面
    for (i = 0; i < n; i++) {
        int page = pages[i];
        int found = 0;
        int least_recently_used = -1;
        int lru_index = -1;

        // 查找页面是否已经在物理块中
        for (j = 0; j < frames; j++) {
            if (frame_list[j] == page) {
                found = 1;
                // 更新最近使用时间
                last_used[j] = i;
                break;
            }
        }

        // 如果没有找到页面，发生缺页
        if (!found) {
            page_faults++;
            // 找到最近最久未使用的页面
            for (j = 0; j < frames; j++) {
                if (frame_list[j] == -1) {
                    // 物理块中有空余位置，直接放入页面
                    frame_list[j] = page;
                    last_used[j] = i;
                    found = 1;
                    break;
                }
                if (last_used[j] < least_recently_used || least_recently_used == -1) {
                    least_recently_used = last_used[j];
                    lru_index = j;
                }
            }

            // 如果物理块已满，替换最久未使用的页面
            if (!found) {
                frame_list[lru_index] = page;
                last_used[lru_index] = i;
            }
        }

        // 打印当前物理块状态
        printf("访问页面 %d: %s，当前物理块: [", page, found ? "不缺页" : "缺页");
        for (j = 0; j < frames; j++) {
            if (frame_list[j] != -1)
                printf(" %d", frame_list[j]);
            else
                printf(" -");
        }
        printf(" ]\n");
    }

    // 计算并输出缺页率
    double page_fault_rate = (double)page_faults / n * 100;
    printf("------------------------------------------\n");
    printf("总页面数: %d\n", n);
    printf("缺页次数: %d\n", page_faults);
    printf("缺页率: %.2f%%\n", page_fault_rate);
}

int main() {
    // 示例页面访问序列
    int pages[] = {7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2, 1, 2, 0, 1, 7, 0, 1};
    int n = sizeof(pages) / sizeof(pages[0]); // 页面总数
    int frames = 3; // 物理块数量

    lruPageReplacement(pages, n, frames);

    return 0;
}
