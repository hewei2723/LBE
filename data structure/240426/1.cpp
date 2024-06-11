#include <stdio.h>  
#include <string.h>  
  
#define NUM 3  
  
struct men {  
    char name[20];  
    char phone[11]; // 假设电话号码为10位数字，包括一个额外的位置存放'\0'  
};  
  
int main() {  
    struct men man[NUM]; // 定义一个men类型的结构数组  
  
    // 输入各个元素的信息  
    for (int i = 0; i < NUM; i++) {  
        printf("请输入第%d个同学的姓名: ", i + 1);  
        gets(man[i].name); 
        printf("请输入第%d个同学的电话号码: ", i + 1);  
        gets(man[i].phone);  
    }  
  
    // 输出各个元素的信息  
    for (int i = 0; i < NUM; i++) {  
        printf("第%d个同学的姓名: %s, 电话号码: %s\n", i + 1, man[i].name, man[i].phone);  
    }  
  
    return 0;  
} 