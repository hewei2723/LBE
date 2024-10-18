/*小蓝最近在研究一种浮点数的表示方法：R 格式。对于一个大于 0 的浮点数 d，
可以用 R 格式的整数来表示。给定一个转换参数 n，将浮点数转换为 R格式整数的做法是：

1. 将浮点数乘以 2n;

2. 四舍五入到最接近的整数。*/
#include<stdio.h>
#include <math.h>
int main(){
    float d;
    int n,g;
    scanf("%d %f",&n,&d);
    g=d*pow(2,n)+0.5;
    printf("%d",g);
}