#include<reg51.h>
//x横坐标接了p0组
//y纵坐标接了p2组
sbit x1=P0^0;
sbit x2=P0^1;
sbit x3=P0^2;
sbit x4=P0^3;
sbit x5=P0^4;
sbit x6=P0^5;

void delay(unsigned int t)
{
    while (t--);
}
void main(){
}