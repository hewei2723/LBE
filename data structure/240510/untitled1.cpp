#include <stdio.h>
#include <stdlib.h>

#define ListSize 100

typedef int DataType;
typedef struct {
	DataType data[ListSize];
	int length;
} SeqList;

void InsertList(SeqList *L, DataType x, int i);
void PrintList(SeqList L);

int main() {
	SeqList L;
	int i, n = 10;
	DataType x;
	
	for (i = 0; i < n; i++)
		L.data[i] = rand() % 100;
	L.length = n;
	
	PrintList(L); // 打印初始顺序表
	
	printf("输入要插入的位置：");
	scanf("%d", &i);
	
	printf("输入要插入的元素：");
	scanf("%d", &x);
	
	InsertList(&L, x, i); // 顺序表插入
	PrintList(L); // 打印插入后的顺序表
	
	return 0;
}

void InsertList(SeqList *L, DataType x, int i) {
	int j;
	
	if (i < 1 || i > L->length + 1) {
		printf("插入位置非法\n");
		exit(0);
	}
	
	if (L->length >= ListSize) {
		printf("顺序表已满，无法插入\n");
		exit(0);
	}
	
	for (j = L->length - 1; j >= i - 1; j--) {
		L->data[j + 1] = L->data[j];
	}
	L->data[i - 1] = x;
	L->length++;
}

void PrintList(SeqList L) {
	int i;
	for (i = 0; i < L.length; i++) {
		printf("%d ", L.data[i]);
	}
	printf("\n");
}
