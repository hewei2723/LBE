#include<reg51.h>
sbit x1=P0^0;
sbit x2=P0^1;
sbit x3=P0^2;
sbit x4=P0^3;
sbit x5=P0^4;
sbit x6=P0^5;
//Y
sbit y1=P2^0;
sbit y2=P2^1;
sbit y3=P2^2;
sbit y4=P2^3;
sbit y5=P2^4;
sbit y6=P2^5;

void delay(unsigned int t)
{
    while (t--);
}
void main(){
	x1=0;
	y1=1;
}