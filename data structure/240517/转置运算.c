#include<stdio.h>
# define MAXSIZE 10

//定义三元组表
typedef struct
{
	int i, j;									//非零元素的行号和列号
	int v;									//非零元素的值
}Triple;
typedef struct
{
	Triple data[MAXSIZE + 1];					//非零元素的三元组表
	int m, n, t;								//矩阵行数、列数和非零元素个数
}TSMatrix;

//建立稀疏矩阵的三元组表
InitTriTupleNode (TSMatrix *M)
{
	int i, j, k,v, row, col;
	row = 0;
	col = 0;
	k = 0;
	while (i != -1 && j != -1)
	{
		k ++;								//记录非零元素的个数
		printf ("输入第%d个非零元素的行号、列号和值：", k);
		scanf ("%d %d %d", &i, &j, &v);
		M -> data[k].i = i;						//存储非零元素的位置和值
		M -> data[k].j = j;
		M -> data[k].v = v;
		if (i > row)  row = i;			//取行、列号最大值，以作为矩阵的行、列数
		if (j > col)  col = j;
}
M -> m = row;						//设置矩阵M的行数、列数和非零元素个数
M -> n = col;
	M -> t = k - 1;
}

//输出稀疏矩阵
void ShowMatrix (TSMatrix *M)
{
	int p, q;
	int t = 1;
	for (p = 1; p <= M -> m; p ++)
	{
		for (q = 1; q <= M -> n; q ++)
			if (M -> data[t].i == p && M -> data[t].j == q)	//输出非零元素
			{
				printf ("%d   ", M -> data[t].v);
				t ++;
}
else  printf ("0   ");				//其他位置输出0
printf ("\n");
}
}

//求稀疏矩阵的转置
void TransMatrix (TSMatrix *M, TSMatrix *N)
{
	int p, q, col;
	N -> m = M -> n;				//设置转置后矩阵N的行数、列数和非零元素个数
	N -> n = M -> m;
	N -> t = M -> t;
	if (N -> t)
	{
		q = 1;
		for (col = 1; col <= M -> n; col ++)		//从M的第一行起进行扫描
			for (p = 1; p <= M -> t; p ++)
				if (M -> data[p].j == col)
				{//将每个三元组中的行号和列号进行交换
					N -> data[q].i = M -> data[p].j;
					N -> data[q].j = M -> data[p].i;
					N -> data[q].v = M -> data[p].v;
					++ q;
}
}
}

int  main ()
{
	TSMatrix M, N;
	TSMatrix *pm = &M, *pn = &N;
	InitTriTupleNode (pm);
	printf ("稀疏矩阵转置前为：\n");
	ShowMatrix (pm);
	printf ("稀疏矩阵转置后为：\n");
	TransMatrix (pm, pn);
	ShowMatrix (pn);
	return 0;
}
