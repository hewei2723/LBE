# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <math.h>
# define MAXSIZE 100
char op[7] = {'+', '-', '*', '/', '(', ')', '#'};				//运算符数组
char cmp[7][7] = {{'>', '>', '<', '<', '<', '>', '>'}, {'>', '>', '<', '<', '<', '>', '>'},
{'>', '>', '>', '>', '<', '>', '>'}, {'>', '>', '>', '>', '<', '>', '>'},
{'<', '<', '<', '<', '<', '=', ' '}, {'>', '>', '>', '>', ' ', '>', '>'}, 
{'<', '<', '<', '<', '<', ' ', '='}};		//运算符优先关系数组

//定义运算符栈
typedef struct								
{
	char elem[MAXSIZE];							
	int top;								
}SeqStackR; 
//定义操作数栈
typedef struct								
{
	int elem[MAXSIZE];					
	int top;								
}SeqStackD;

//初始化运算符栈
void InitStackR (SeqStackR *S)
{
	S -> top = 0;
}

//初始化操作数栈
void InitStackD (SeqStackD *S)
{
	S -> top = 0;
}
//运算符进栈
void PushR (SeqStackR *S, char e)
{
	if (S -> top == MAXSIZE)
		printf ("The operator stack is full!\n");
else
{
		S -> elem[S -> top] = e;
	S -> top ++;
}
}
//操作数进栈
void PushD (SeqStackD *S, int e)
{
	if (S -> top == MAXSIZE)
		printf ("The operand stack is full!\n");
else
{
		S -> elem[S -> top] = e;
		S -> top ++;
}
}
//运算符出栈
void PopR (SeqStackR *S, char *e)
{
	if (S -> top == 0)
		printf ("The operator stack is null!\n");
	else
	{
		S -> top --;
		*e = S -> elem[S -> top];
}
}
//操作数出栈
void PopD (SeqStackD *S, int *e)
{
	if (S -> top == 0)
		printf ("The operand stack is null!\n");
	else
	{
		S -> top --;
		*e = S -> elem[S -> top];
}
}
//运算符栈取栈顶元素
char GetTopR (SeqStackR *S)
{
	if (S -> top == 0)
		printf ("The operator stack is null!\n");
	else
		return (S -> elem[S -> top - 1]);
}
//操作数栈取栈顶元素
int GetTopD (SeqStackD *S)
{
	if (S -> top == 0)
			printf ("The operator stack is null!\n");
	else		return (S -> elem[S -> top - 1]);
}

//输入字符是否属于运算符集合，如果是，返回它在数组中的位置；否则，返回-1
int Isoperator (char ch)
{
	int i;
	for (i = 0; i < 7; i ++)
	{
		if (ch == op[i])
			return i;
}
return -1;
}

//比较两个运算符的优先级
char Compare (char ch1, char ch2)
{
	int m, n;
	m = Isoperator (ch1);
	n = Isoperator (ch2);
	return cmp[m][n];
}

//返回两个操作数运算的结果
int Execute (int a, char theta, int b)
{
	int result;
	switch (theta)
	{
		case '+' :
			result = a + b;
			break;
		case '-' :
			result = a - b;
			break;
		case '*' :
			result = a * b;
			break;
		case '/' :
			result = a / b;
			break;
}
return result;
}

//输入算术表达式并求值
int EvaluateExp ()
{
	char ch;
	int a=0,b=0;
	char theta;
	char str[50];
	int k = 0;
	int x = 0;
	SeqStackR OPTR;							//定义OPTR为运算符栈
SeqStackD OPND;							//定义OPND为操作数栈
	InitStackR (&OPTR);						//初始化运算符栈
	InitStackD (&OPND);						//初始化操作数栈
	printf ("Please input expression: \n");
	PushR (&OPTR, '#');						//使'#'进栈
	gets (str);									//输入算术表达式
	ch = str[k];								//获取算术表达式的第一个字符
	k ++;
	while (ch != '#' || GetTopR (&OPTR) != '#')
	{
		if (Isoperator(ch) == -1)					//当前字符为操作数
		{
			x = ch - '0';						//将当前字符转换为十进制数
			ch = str[k];						//读取下一个字符
			k ++;
			while (Isoperator(ch) == -1)			//下一个字符仍为操作数
			{
				x =x * 10 + ch - '0';				//将操作数转换为多位整数
				ch = str[k];
				k ++;
}
PushD (&OPND, x);				//操作数进栈
}
else									//当前字符为运算符
{
		switch (Compare (GetTopR (&OPTR), ch)) 
		{	//比较运算符栈顶元素与当前运算符的优先级
			case '<' :				//栈顶元素优先级小于当前读入字符优先级
				PushR (&OPTR, ch);		//当前读入字符进栈
				ch = str[k];				//读取下一个字符
				k ++;
				break;
			case '=' :				//栈顶元素优先级等于当前读入字符优先级
				PopR (&OPTR, &ch);		//运算符出栈
				ch = str[k];				//读取下一个字符
				k ++;
				break;
			case '>' :				//栈顶元素优先级大于当前读入字符优先级
				PopR (&OPTR, &theta);		//运算符出栈
				PopD (&OPND, &b);		//两个操作数出栈
				PopD (&OPND, &a);
				PushD (&OPND, Execute (a, theta, b));//两个操作数运算结果进栈
				break;
}
}
}
return GetTopD (&OPND);					//返回操作数栈顶元素为运算结果
}

 int main ()
{
	while(1){
		//TODO
	printf ("The value of the expression is: %d\n", EvaluateExp ());
	}
}
