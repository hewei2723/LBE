#include <stdio.h>
int main(){
    int a[5]={8,9,10,11,12};
    int b[5];//用来存储余数，剩下的苹果
    for (int i = 0; i < 5; i++)
    {
        a[i+1]=a[i+1]+a[i]/3;
        a[4-i]=a[4-i]+a[i]/3;
        a[i]=a[i]-a[i]/3;
    }
    for (int i = 0; i < 5; i++)
    {
        printf("%d ",a[i]);
    }
}