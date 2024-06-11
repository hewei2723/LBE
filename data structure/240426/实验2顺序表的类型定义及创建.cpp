#include <stdio.h>  
#include <stdlib.h>  
#include <time.h>  
  
// 顺序表的定义  
#define ListSize 100 // 表空间大小  
  
typedef int DataType; // 数据类型  
  
typedef struct {  
    DataType data[ListSize]; // 向量data用于存放表结点  
    int length; // 当前的表长度  
} SeqList;  
  
// 函数声明  
void CreateList(SeqList *L, int n);  
void PrintList(SeqList L, int n);  
  
int main() {  
    SeqList L;  
    int n = 10; // 欲建立的顺序表长度  
    L.length = 0;  
  
    CreateList(&L, n); // 建立顺序表  
    PrintList(L, n); // 打印顺序表  
  
    return 0;  
}  
  
// 顺序表的建立  
void CreateList(SeqList *L, int n) {  
    srand(time(NULL)); // 初始化随机数种子  
    for (int i = 0; i < n; i++) {  
        L->data[i] = rand() % 100; // 填充0到99的随机数  
    }  
    L->length = n; // 设置顺序表的长度  
}  
  
// 顺序表的打印  
void PrintList(SeqList L, int n) {  
    for (int i = 0; i < n; i++) {  
        printf("%d ", L.data[i]);  
    }  
    printf("\n");  
}
