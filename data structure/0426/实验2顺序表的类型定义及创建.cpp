#include <stdio.h>
//顺序表的定义：
#define ListSize 100		//表空间大小可根据实际需要而定，这里假设为100
typedef int DataType;		//DataType可以是任何相应的数据类型如int, float或char
typedef struct
{	DataType data[ListSize];	//向量data用于存放表结点
	int length;				//当前的表长度
}SeqList;
int main()
{
	SeqList L;
	int n=10;				//欲建立的顺序表长度
	L.length=0;
	void CreateList(SeqList *L,int n);
	void PrintList(SeqList L,int n);
	CreateList(&L,n);		//建立顺序表
	PrintList(L,n);			//打印顺序表

}
//顺序表的建立：
void CreateList(SeqList *L,int n)
{	
	for (int i=0;i<n;i++){
		
	}
}

//顺序表的打印：
void PrintList(SeqList L,int n)
{	
}
