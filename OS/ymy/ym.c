#include <stdio.h>
#include <limits.h>

void optimalPageReplacement(int pages[], int n, int frames) {
    int frame_list[frames];   // 当前物理块
    int page_faults = 0;      // 缺页次数
    int i, j, k;

    // 初始化物理块为空
    for (i = 0; i < frames; i++) {
        frame_list[i] = -1;
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

        // 检查页面是否已在物理块中
        for (j = 0; j < frames; j++) {
            if (frame_list[j] == page) {
                found = 1;
                break;
            }
        }

        if (!found) {
            // 发生缺页
            page_faults++;
            int index_to_replace = -1;

            if (i < frames) {
                // 物理块未满时直接添加
                frame_list[i] = page;
            } else {
                // 找到需要替换的页面
                int farthest = -1;
                for (j = 0; j < frames; j++) {
                    int next_use = INT_MAX; // 未找到，认为不会再使用
                    for (k = i + 1; k < n; k++) {
                        if (pages[k] == frame_list[j]) {
                            next_use = k;
                            break;
                        }
                    }
                    if (next_use > farthest) {
                        farthest = next_use;
                        index_to_replace = j;
                    }
                }
                frame_list[index_to_replace] = page;
            }
            // 打印当前状态
            printf("访问页面 %d: 缺页，当前物理块: [", page);
            for (j = 0; j < frames; j++) {
                if (frame_list[j] != -1)
                    printf(" %d", frame_list[j]);
                else
                    printf(" -");
            }
            printf(" ]\n");
        } else {
            // 不缺页，打印当前状态
            printf("访问页面 %d: 不缺页，当前物理块: [", page);
            for (j = 0; j < frames; j++) {
                if (frame_list[j] != -1)
                    printf(" %d", frame_list[j]);
                else
                    printf(" -");
            }
            printf(" ]\n");
        }
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

    optimalPageReplacement(pages, n, frames);

    return 0;
}
