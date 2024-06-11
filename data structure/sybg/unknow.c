# include <stdlib.h>
# include <stdio.h>
# define MAX_VERTEX_NUM 30				//最大顶点个数

//图的邻接表存储结构
typedef struct ArcNode							
{
	int adjvex;								//邻接点的序号
	struct ArcNode *next;						//指向下一个邻接顶点的指针
}ArcNode;
typedef struct VertexNode
{
	char data;									//顶点数据
	struct ArcNode *firstarc;						//指向该顶点的第一个邻接点的指针
}VertexNode;
typedef struct
{
	VertexNode vertex[MAX_VERTEX_NUM];		//顶点向量
	int vexnum, arcnum;						//顶点数和弧数
}ALGraph;

//采用邻接表表示法建立无向图G
void CreateUDG (ALGraph *G)
{	
	int i, j, k;
	ArcNode *s;
	printf ("输入顶点数和弧数：");
	scanf ("%d %d", &G -> vexnum, &G -> arcnum);	//输入顶点数和弧数
	printf ("输入顶点信息\n");
	for (i = 0; i < G -> vexnum; i ++)				//建立有n个顶点的顶点表
	{	
		getchar();
		printf ("第%d个顶点：", i);
scanf ("%c", & G -> vertex[i].data);		//输入顶点信息
G -> vertex[i].firstarc = NULL;			//顶点的指针为空
}
printf ("输入边的信息\n");
	for (k = 0; k < G -> arcnum; k ++)				//建立各个顶点的单链表
	{
		printf ("第%d条边——起点序号，终点序号：", k);
		scanf ("%d %d", &i, &j);				//输入弧<vi, vj>对应顶点的位置
		s = (ArcNode*) malloc (sizeof (ArcNode));	//生成新结点
		s -> adjvex = j;						//邻接点位置为j
		s -> next = G -> vertex[i].firstarc;	//将新结点插入到顶点vi的链表的头结点后
		G -> vertex[i].firstarc = s;
		s = (ArcNode*) malloc (sizeof (ArcNode));	//生成新结点
		s -> adjvex = i;						//邻接点位置为i
		s -> next = G -> vertex[j].firstarc;	//将新结点插入到顶点vj的链表的头结点后
		G -> vertex[j].firstarc = s;
}
}

//深度优先遍历的非递归算法
void DFS (ALGraph G, int v)
{
	int w, visited[MAX_VERTEX_NUM]={0};		//定义访问标志数组并初始化
	int stack[MAX_VERTEX_NUM], top = 0;		//定义堆栈并初始化
	ArcNode *p;
	printf ("%c", G.vertex[v].data);				//输出起始顶点
	visited[v] = 1;								//起始顶点访问标记为1
	top ++;									//起始顶点进栈
	stack[top] = v;
	p = G.vertex[v].firstarc;						//指向起始顶点第一个邻接点的指针
	while (1)
	{
		while (p && visited[p -> adjvex] == 1)		//该顶点已被访问，指向下一个顶点
			p = p -> next;
		if (p)								
		{
			w = p -> adjvex;					//取p所指顶点序号
			printf ("%c", G.vertex[w].data);		//取与顶点序号对应的顶点值
			visited[w] = 1;						//访问标记设为1
			top ++;							//访问过的顶点进栈
			stack[top] = w;
			p = G.vertex[w].firstarc;
}
else			//如果p为空，则回溯查找已被访问顶点的未被访问的邻接点
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
	printf ("输入起始点序号：")	;
	scanf ("%d", &v);
	printf ("深度遍历序列为：");
	DFS (G, v);
}
