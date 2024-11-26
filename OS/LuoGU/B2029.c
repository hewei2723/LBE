#include <stdio.h>
/*一只大象口渴了，要喝 
20 升水才能解渴，但现在只有一个深 
h 厘米，底面半径为 
r 厘米的小圆桶 （
h 和 
r 都是整数）。问大象至少要喝多少桶水才会解渴。 */
int main(){
    int h=23 ,r=11;
    int v=3.14*r*r*h;
    int n=20/v;
    printf("%d",n);
}