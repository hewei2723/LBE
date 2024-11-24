#include <reg51.h>
#include <DS18B20.h>
sbit le=P1^0; 
int cp;
unsigned char seven_seg[] = {0xc0, 0xf9, 0xa4, 0xb0, 0x99, 0x92, 0x82, 0xf8, 0x80, 0x90};  
unsigned char bit_scan[] = {0x80,0x40,0x20,0x10,0x08,0x04,0x02,0x01}; 
void latch(){le=1;le=0;}
//void delay(unsigned int x){while(x--);}
void display_num(int i,int j){
	P0=0xff;P0=bit_scan[i];latch();P0=seven_seg[j];delay(500);
}
void timer0_isr(void) interrupt 1 { //计数器溢出中断
    TH0 = (65536 - 2000) / 256;
    TL0 = (65536 - 2000) % 256;
    cp++;
}
void time_init(){
	TMOD = 0x01;
    TH0 = (65536 - 2000) / 256;
    TL0 = (65536 - 2000) % 256;
    EA = 1;
    ET0 = 1;
    TR0 = 1;
}
void main(){
	time_init();
	while(1){
		ReadTemperature();
	}
}