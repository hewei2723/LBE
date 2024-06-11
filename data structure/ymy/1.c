#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100 // 定义顺序表的最大容量

typedef struct {
    int data[MAX_SIZE]; // 用数组存储数据
    int length; // 记录当前顺序表中元素的个数
} SeqList;

// 初始化顺序表
void InitList(SeqList *list) {
    list->length = 0; // 初始时顺序表中元素个数为0
}

// 插入元素
int Insert(SeqList *list, int index, int element) {
    if (index < 0 || index > list->length || list->length == MAX_SIZE) {
        printf("插入位置不合法或顺序表已满\n");
        return 0; // 插入失败
    }
    
    // 将插入位置之后的元素依次向后移动一位
    for (int i = list->length - 1; i >= index; i--) {
        list->data[i + 1] = list->data[i];
    }
    
    list->data[index] = element; // 插入元素
    list->length++; // 长度加1
    return 1; // 插入成功
}

// 删除元素
int Delete(SeqList *list, int index) {
    if (index < 0 || index >= list->length) {
        printf("删除位置不合法\n");
        return 0; // 删除失败
    }
    
    // 将删除位置之后的元素依次向前移动一位
    for (int i = index + 1; i < list->length; i++) {
        list->data[i - 1] = list->data[i];
    }
    
    list->length--; // 长度减1
    return 1; // 删除成功
}

// 打印顺序表中的元素
void PrintList(SeqList *list) {
    printf("顺序表中的元素为: ");
    for (int i = 0; i < list->length; i++) {
        printf("%d ", list->data[i]);
    }
    printf("\n");
}

int main() {
    SeqList list;
    InitList(&list);

    // 插入元素
    Insert(&list, 0, 1);
    Insert(&list, 1, 2);
    Insert(&list, 2, 3);
    PrintList(&list); // 1 2 3

    // 删除元素
    Delete(&list, 1);
    PrintList(&list); // 1 3

    return 0;
}
