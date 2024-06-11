#include "stdio.h"
#define MAXN  26
char q[MAXN];
int head = 0, tail = -1;
int en_queue(char x) {
    if (tail == MAXN-1)
        return 1;
    q[++tail] = x;
    return 0;
}

int de_queue(char *p_y) {
    if (head > tail)
        return 1;
    *p_y = q[head++];
    return 0;
}

int main() {
    int i;
    char ch_x, ch_y;

    printf("请输入你要入队的字符（输入'0'结束）:\n");
    while (1) {
        scanf("%c", &ch_x);
        getchar();  // 消耗换行符
        if (ch_x == '0')
            break;
        if (en_queue(ch_x) == 1)  
            printf("入队失败!\n");
        else {
            printf("入队成功!\n");
            printf("请输入下一个字符（输入'0'结束）:\nch_x=");
        }
    }

    printf("入队操作后的队列内容:\n");
    for (i = head; i <= tail; i++) {
        printf("%c ", q[i]);
    }
    printf("\n");

    while (1) {
        char command;
        printf("请输入操作指令（d表示出队，q表示退出）:\n");
        scanf("%c", &command);
        getchar();  // 消耗换行符
        if (command == 'q')
            break;
        if (command == 'd') {
            if (de_queue(&ch_y) == 1)
                printf("出队失败!\n");
            else {
                printf("出队成功!\n");
                printf("出队的字符是 %c\n", ch_y);
            }
        }

        printf("当前队列内容:\n");
        for (i = head; i <= tail; i++) {
            printf("%c ", q[i]);
        }
        printf("\n");
    }

    return 0;
}