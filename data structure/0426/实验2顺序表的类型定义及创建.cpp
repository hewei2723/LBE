#include <stdio.h>
//˳���Ķ��壺
#define ListSize 100		//��ռ��С�ɸ���ʵ����Ҫ�������������Ϊ100
typedef int DataType;		//DataType�������κ���Ӧ������������int, float��char
typedef struct
{	DataType data[ListSize];	//����data���ڴ�ű���
	int length;				//��ǰ�ı���
}SeqList;
int main()
{
	SeqList L;
	int n=10;				//��������˳�����
	L.length=0;
	void CreateList(SeqList *L,int n);
	void PrintList(SeqList L,int n);
	CreateList(&L,n);		//����˳���
	PrintList(L,n);			//��ӡ˳���

}
//˳���Ľ�����
void CreateList(SeqList *L,int n)
{	
	for (int i=0;i<n;i++){
		
	}
}

//˳���Ĵ�ӡ��
void PrintList(SeqList L,int n)
{	
}
