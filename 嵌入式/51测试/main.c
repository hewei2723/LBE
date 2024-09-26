#include <reg51.h>
sbit LED=P0^0;
void delay(unsigned int x){
while(x--);
}
void main(){
	LED=0;
	delay(25000);
	LED=1;
	delay(25000);
}