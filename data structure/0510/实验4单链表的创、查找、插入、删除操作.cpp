#include <stdio.h>
#include <stdlib.h>
//������Ķ��壺
typedef char DataType;		//DataType�������κ���Ӧ������������int, float��char
typedef struct node			//������Ͷ���
{	DataType data;			//����������
	struct node *next;		//����ָ����
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
	head=CreateListR1();	//����������
	PrintList(head);		//��ӡ������
	printf("�������������Ԫ�أ�");
	scanf("%c",&x);
	printf("������������Ԫ�ص�λ�ã�");
	scanf("%d",&i);
	InsertList(head,x,i);
	PrintList(head);		//��ӡ������
	printf("��������ɾ������λ�ã�");
	scanf("%d",&i);
	DeleteList(head,i);
	PrintList(head);		//��ӡ������
}

//������Ľ�����
LinkList CreateListR1(void)
{	char ch;
	LinkList head=(ListNode *)malloc(sizeof(ListNode));
	ListNode *s,*r;
	r=head;					//βָ���ֵָ��ͷ���
	while ((ch=getchar())!='\n')
	{	s=(ListNode *)malloc(sizeof(ListNode));	//�����½��
		s->data=ch;
		r->next=s;
		r=s;
	}
	r->next=NULL;
	return head;			//����ͷָ��
}

//������Ĵ�ӡ��
void PrintList(LinkList head)
{
	ListNode *p;
	for(p=head->next;p;p=p->next)
		printf("%c",p->data);
	printf("\n");
}

//������Ĳ���
LinkList GetNode(LinkList head,int i)
{//�ڴ�ͷ���ĵ�����head�в��ҵ�i�����
	int j;
	ListNode *p;
	p=head;j=0;				//��ͷ��㿪ʼɨ��
	while(p && j<i)
	{	p=p->next;j++;
	}
	return p;				//���ص�i�����
}
//������Ĳ���
void InsertList(LinkList head,DataType x,int i)
{//��ֵΪx���½����뵽��ͷ���ĵ�����head�ĵ�i������λ����
	ListNode *p,*s;
	p=GetNode(head,i-1);	//Ѱ�ҵ�i-1�����
	









}
//�������ɾ��
void DeleteList(LinkList head,int i)
{//ɾ����ͷ���ĵ������еĵ�i�����
	ListNode *p,*r;
	p=GetNode(head,i-1);	//Ѱ�ҵ�i-1�����










		
}
