# include <stdlib.h>
# include <stdio.h>
# define MAX_VERTEX_NUM 30				//��󶥵����

//ͼ���ڽӱ�洢�ṹ
typedef struct ArcNode							
{
	int adjvex;								//�ڽӵ�����
	struct ArcNode *next;						//ָ����һ���ڽӶ����ָ��
}ArcNode;
typedef struct VertexNode
{
	char data;									//��������
	struct ArcNode *firstarc;						//ָ��ö���ĵ�һ���ڽӵ��ָ��
}VertexNode;
typedef struct
{
	VertexNode vertex[MAX_VERTEX_NUM];		//��������
	int vexnum, arcnum;						//�������ͻ���
}ALGraph;

//�����ڽӱ��ʾ����������ͼG
void CreateUDG (ALGraph *G)
{	
	int i, j, k;
	ArcNode *s;
	printf ("���붥�����ͻ�����");
	scanf ("%d %d", &G -> vexnum, &G -> arcnum);	//���붥�����ͻ���
	printf ("���붥����Ϣ\n");
	for (i = 0; i < G -> vexnum; i ++)				//������n������Ķ����
	{	
		getchar();
		printf ("��%d�����㣺", i);
scanf ("%c", & G -> vertex[i].data);		//���붥����Ϣ
G -> vertex[i].firstarc = NULL;			//�����ָ��Ϊ��
}
printf ("����ߵ���Ϣ\n");
	for (k = 0; k < G -> arcnum; k ++)				//������������ĵ�����
	{
		printf ("��%d���ߡ��������ţ��յ���ţ�", k);
		scanf ("%d %d", &i, &j);				//���뻡<vi, vj>��Ӧ�����λ��
		s = (ArcNode*) malloc (sizeof (ArcNode));	//�����½��
		s -> adjvex = j;						//�ڽӵ�λ��Ϊj
		s -> next = G -> vertex[i].firstarc;	//���½����뵽����vi�������ͷ����
		G -> vertex[i].firstarc = s;
		s = (ArcNode*) malloc (sizeof (ArcNode));	//�����½��
		s -> adjvex = i;						//�ڽӵ�λ��Ϊi
		s -> next = G -> vertex[j].firstarc;	//���½����뵽����vj�������ͷ����
		G -> vertex[j].firstarc = s;
}
}

//������ȱ����ķǵݹ��㷨
void DFS (ALGraph G, int v)
{
	int w, visited[MAX_VERTEX_NUM]={0};		//������ʱ�־���鲢��ʼ��
	int stack[MAX_VERTEX_NUM], top = 0;		//�����ջ����ʼ��
	ArcNode *p;
	printf ("%c", G.vertex[v].data);				//�����ʼ����
	visited[v] = 1;								//��ʼ������ʱ��Ϊ1
	top ++;									//��ʼ�����ջ
	stack[top] = v;
	p = G.vertex[v].firstarc;						//ָ����ʼ�����һ���ڽӵ��ָ��
	while (1)
	{
		while (p && visited[p -> adjvex] == 1)		//�ö����ѱ����ʣ�ָ����һ������
			p = p -> next;
		if (p)								
		{
			w = p -> adjvex;					//ȡp��ָ�������
			printf ("%c", G.vertex[w].data);		//ȡ�붥����Ŷ�Ӧ�Ķ���ֵ
			visited[w] = 1;						//���ʱ����Ϊ1
			top ++;							//���ʹ��Ķ����ջ
			stack[top] = w;
			p = G.vertex[w].firstarc;
}
else			//���pΪ�գ�����ݲ����ѱ����ʶ����δ�����ʵ��ڽӵ�
		if (top > 1)
		{
			top --;
		    w = stack[top];
		    p = G.vertex[w].firstarc;
}
else  break;
}
printf("\n");
}

void main ()
{
	ALGraph G;
	int v;
	CreateUDG (&G);
	printf ("������ʼ����ţ�")	;
	scanf ("%d", &v);
	printf ("��ȱ�������Ϊ��");
	DFS (G, v);
}
