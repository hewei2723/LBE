//建立同学通讯录
//要求：本程序中定义了一个结构men，它有两个成员name和phone用来表示
//姓名和电话号码。在主函数中定义man为具有men类型的结构数组。在for语句中，用gets函数分别输入各个元素中两个成员的值。
//然后又在for语句中用printf语句输出各元素中两个成员值。
#include"stdio.h"
#define NUM 1
struct men
{
	char name[20];
	char phone[10];
};
int main()
{
	struct men man[NUM];
	for (int i=0;i<=NUM;i++){
		printf("name:");
		gets(man[i].name);
		printf("phone:");
		gets(man[i].phone);
	}
	for(int i=0;i<=NUM;i++){
		printf("name:%s phone:%s",man[i].name,man[i].phone);
	}
}

