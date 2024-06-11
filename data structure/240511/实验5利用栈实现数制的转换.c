#include <stdio.h>
#include <stdlib.h>

#define StackSize 100 //假定预分配的栈空间最多为100个元素

typedef int DataType; //应将顺序栈的DataType定义改为整型
typedef struct {
	DataType data[StackSize];
	int top;
} SeqStack;

void InitStack(SeqStack *S) {
	//将顺序栈置空
	S->top = -1;
}

int StackEmpty(SeqStack *S) {
	return S->top == -1;
}

int StackFull(SeqStack *S) {
	return S->top == StackSize - 1;
}

void Push(SeqStack *S, DataType x) {
	if (StackFull(S)) {
		printf("Stack is full.\n");
		exit(EXIT_FAILURE); // 栈满，无法入栈，程序退出
	} else {
		S->data[++(S->top)] = x; // 先将栈顶指针加1，然后将元素x入栈
	}
}

DataType Pop(SeqStack *S) {
	if (StackEmpty(S)) {
		printf("Stack is empty.\n");
		exit(EXIT_FAILURE); // 栈空，无法出栈，程序退出
	} else {
		return S->data[(S->top)--]; // 先取栈顶元素，再将栈顶指针减1
	}
}

DataType StackTop(SeqStack *S) {
	if (StackEmpty(S)) {
		printf("Stack is empty.\n");
		exit(EXIT_FAILURE); // 栈空，无法获取栈顶元素，程序退出
	}
	return S->data[S->top];
}
void MultiBaseOutput(int N, int B) {
	SeqStack S;
	InitStack(&S);
	printf("%d转换为%d进制数为：", N, B);
	while (N != 0) {
		Push(&S, N % B); // 将N除以B的余数入栈
		N = N / B; // 更新N为N除以B的商
	}
	while (!StackEmpty(&S)) {
		printf("%d", Pop(&S)); // 依次出栈并打印，得到转换后的结果
	}
	printf("\n");
}
int main() {
	while (1) {
		int N, B;
		printf("请输入欲转换的十进制数：");
		scanf("%d", &N);
		printf("请输入欲转换成的进制：");
		scanf("%d", &B);
		MultiBaseOutput(N, B);
	}
}
