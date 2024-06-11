#include <stdio.h>  
#include <stdlib.h>  
#include <time.h>  
  
// ˳���Ķ���  
#define ListSize 100 // ��ռ��С  
  
typedef int DataType; // ��������  
  
typedef struct {  
    DataType data[ListSize]; // ����data���ڴ�ű���  
    int length; // ��ǰ�ı���  
} SeqList;  
  
// ��������  
void CreateList(SeqList *L, int n);  
void PrintList(SeqList L, int n);  
  
int main() {  
    SeqList L;  
    int n = 10; // ��������˳�����  
    L.length = 0;  
  
    CreateList(&L, n); // ����˳���  
    PrintList(L, n); // ��ӡ˳���  
  
    return 0;  
}  
  
// ˳���Ľ���  
void CreateList(SeqList *L, int n) {  
    srand(time(NULL)); // ��ʼ�����������  
    for (int i = 0; i < n; i++) {  
        L->data[i] = rand() % 100; // ���0��99�������  
    }  
    L->length = n; // ����˳���ĳ���  
}  
  
// ˳���Ĵ�ӡ  
void PrintList(SeqList L, int n) {  
    for (int i = 0; i < n; i++) {  
        printf("%d ", L.data[i]);  
    }  
    printf("\n");  
}
