#include <stdio.h>
#include <stdlib.h>
//单链表的定义：
typedef char DataType;		//DataType可以是任何相应的数据类型如int, float或char
typedef struct node			//结点类型定义
{	DataType data;			//结点的数据域
	struct node *next;		//结点的指针域
}ListNode;
typedef ListNode *LinkList;

int main()
{
	LinkList head;
	DataType x;
	int i;
	LinkList CreateListR1(void);
	LinkList GetNode(LinkList head,int i);
	void InsertList(LinkList head,DataType x,int i);
	void DeleteList(LinkList head,int i);
	void PrintList(LinkList head);
	head=CreateListR1();	//建立单链表
	PrintList(head);		//打印单链表
	printf("请输入欲插入的元素：");
	scanf("%c",&x);
	printf("请输入欲插入元素的位置：");
	scanf("%d",&i);
	InsertList(head,x,i);
	PrintList(head);		//打印单链表
	printf("请输入欲删除结点的位置：");
	scanf("%d",&i);
	DeleteList(head,i);
	PrintList(head);		//打印单链表
}

//单链表的建立：
LinkList CreateListR1(void)
{	char ch;
	LinkList head=(ListNode *)malloc(sizeof(ListNode));
	ListNode *s,*r;
	r=head;					//尾指针初值指向头结点
	while ((ch=getchar())!='\n')
	{	s=(ListNode *)malloc(sizeof(ListNode));	//生成新结点
		s->data=ch;
		r->next=s;
		r=s;
	}
	r->next=NULL;
	return head;			//返回头指针
}

//单链表的打印：
void PrintList(LinkList head)
{
	ListNode *p;
	for(p=head->next;p;p=p->next)
		printf("%c",p->data);
	printf("\n");
}

//单链表的查找
LinkList GetNode(LinkList head,int i)
{//在带头结点的单链表head中查找第i个结点
	int j;
	ListNode *p;
	p=head;j=0;				//从头结点开始扫描
	while(p && j<i)
	{	p=p->next;j++;
	}
	return p;				//返回第i个结点
}
//单链表的插入
void InsertList(LinkList head,DataType x,int i)
{//将值为x的新结点插入到带头结点的单链表head的第i个结点的位置上
	ListNode *p,*s;
	p=GetNode(head,i-1);	//寻找第i-1个结点
	









}
//单链表的删除
void DeleteList(LinkList head,int i)
{//删除带头结点的单链表中的第i个结点
	ListNode *p,*r;
	p=GetNode(head,i-1);	//寻找第i-1个结点










		
}
