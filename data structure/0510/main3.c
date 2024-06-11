#include <stdio.h>
#include <stdlib.h>
//顺序表的定义：
#define ListSize 100		//表空间大小可根据实际需要而定，这里假设为100
typedef int DataType;		//DataType可以是任何相应的数据类型如int, float或char
typedef struct
{	DataType data[ListSize];	//向量data用于存放表结点
	int length;				//当前的表长度
}SeqList;

int main()
{
	void InsertList(SeqList *L,DataType x,int i);
	void PrintList(SeqList L);
	SeqList L;
	int i,n=10;
	DataType x;
	for (i=0;i<n;i++)
		L.data[i]=rand()%100;
	L.length=n;
	PrintList(L);			//打印顺序表
	printf("输入要插入的位置：");
	scanf("%d",&i);
	printf("输入要插入的元素：");
	scanf("%d",&x);
	InsertList(&L,x,i);		//顺序表插入
	PrintList(L);			//打印顺序表
	return 0;
}
//顺序表的插入：
void InsertList(SeqList *L,DataType x,int i)
{//将新结点x插入L所指的顺序表的第i个结点的位置
    int j;
    if(i<1||i>L->length+1){
        printf("插入位置不合法\n");
        return;
    }
    if(L->length>=ListSize){
        printf("表已满，无法插入\n");
        return;
    }
    for(j=L->length-1;j>=i-1;j--)
        L->data[j+1]=L->data[j];
	    L->data[i-1]=x;
	    L->length++;
    return;
}
//顺序表的打印：
void PrintList(SeqList L)
{	int i;
	for (i=0;i<L.length;i++)
		printf("%d  ",L.data[i]);
	printf("\n");
}
