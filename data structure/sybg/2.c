#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define ListSize 100 // 顺序表最大容量
typedef int DataType; // 数据类型
typedef struct {
    DataType data[ListSize]; // 顺序表存储数据的数组
    int length; // 当前长度
} SeqList;
// 创建顺序表
void CreateList(SeqList *L, int n);
// 打印顺序表
void PrintList(SeqList L);
int main() {
    SeqList L;
    int n = 10; // 要生成的随机数个数
    CreateList(&L, n); // 创建顺序表
    PrintList(L); // 打印顺序表

    return 0;
}
// 创建顺序表
void CreateList(SeqList *L, int n) {
    srand(time(NULL)); // 初始化随机数种子
    for (int i = 0; i < n; i++) {
        L->data[i] = rand() % 100; // 生成0到99的随机数
    }
    L->length = n; // 更新顺序表的长度
}
// 打印顺序表
void PrintList(SeqList L) {
    printf("顺序表中的元素为: ");
    for (int i = 0; i < L.length; i++) {
        printf("%d ", L.data[i]);
    }
    printf("\n");
}