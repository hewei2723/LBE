#include<reg51.h>
sbit LED=p2^0;
void delay(int x){
	while(-1);
}
void main(){
	LED=0;
	delay(5000);
	LED=1;
	delay(2000);
}