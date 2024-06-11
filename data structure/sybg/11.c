#include <stdio.h>
#include <string.h>
#define MAX 50								//定义查找表的最大长度

//定义结构体类型
typedef struct	
{ 
	char no[5];								//学号
	char name[10];							//姓名
	int score;									//成绩
}RecordType;
typedef struct									//定义查找表的顺序存储结构
{
	RecordType elem[MAX + 1];			
	int length;								//查找表的长度
}SeqList;

//在顺序表L中折半查找关键字等于key的数据元素，若找到，返回值为该元素
//在表中的位置，否则为0
int BinSearch (SeqList L, char *key)
{ 
	int low, high, mid;
	low = 1;
	high = L.length;							//设置初始查找区间
	while (low <= high)
	{
		mid = (low + high) / 2;					//求中间位置
		if (strcmp (L.elem[mid].no, key) == 0)  
			return mid;						//查找成功，返回该元素所在位置
		else if (strcmp (L.elem[mid].no, key) > 0) 
			high = mid - 1;						//查找区间为表的前半部分
		else  low = mid + 1;					//查找区间为表的后半部分
	}
	return 0;									//查找不成功，返回0
}

void main ()
{
	int N, i = 1, loc;
	char key[5];
	SeqList L;
	printf ("请输入学生总数（1—%d）：", MAX);
	scanf ("%d", &N);
	L.length = N;
	printf ("输入学生成绩表（按照学号递增有序）：\n");
	printf ("输入第1个学生记录：");
	scanf ("%s %s %d", &L.elem[i].no, &L.elem[i].name, &L.elem[i].score);
	i ++;
	while (i <= N)
	{
		printf ("输入第%d个学生记录：", i);
		scanf ("%s %s %d", &L.elem[i].no, &L.elem[i].name, &L.elem[i].score);
		if (strcmp (L.elem[i].no, L.elem[i - 1].no) > 0)	//使输入序列按学号递增有序
			i ++;
		else
			printf ("你输入的记录不满足要求，请重新输入。\n");
	}
	printf ("输入要查找的学生的学号：");
	scanf ("%s", key);
	loc = BinSearch (L, key);
	if (loc == 0)
		printf ("未找到该学生的成绩！\n");
	else
	printf ("找到该学生的成绩，其学号为：%s，成绩为：%d\n", L.elem[loc].no, L.elem[loc].score);
	printf ("程序运行结束。\n");
	return;
}