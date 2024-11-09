#include<reg51.h>
sbit LE=P1^0;
sbit key1=P2^0;//选择时间，按下的时候时间暂停同时选择时间
sbit key2=P2^1;//时间+
sbit key3=P2^2;//时间-
sbit key4=P2^3;//开始计时
int cp=0,cpfh=0;time=0,flash = 0x00,start=1,mode=1;
int secondA,hourA,minuteA,secondB,minuteB,hourB;
int poi[]={0x80,0x40,0x20,0x10,0x08,0x04,0x02,0x01};
unsigned char seven_seg[] ={0xc0,0xf9,0xa4,0xb0,0x99,0x92,0x82,0xf8,0x80,0x90};
void latch(){
	LE=1;
	LE=0;
}
void delay(int x){while(x--);}
void STM(int time) {
    secondA = (time % 60) / 10;
    secondB = (time % 60) % 10;
    minuteA = (time / 60 % 60) / 10;
    minuteB = (time / 60 % 60) % 10;
    hourA = (time / 3600) / 10;
    hourB = (time / 3600) % 10;
}
void timer0_isr() interrupt 1
{
	TH0 = (65535 - 5000) / 256;
	TL0 = (65535 - 5000) % 256;
	cp++;
	cpfh++;
	if(cp>50&&start==1){
		time++;
		cp=0;
	}//产生时间
	//从系统运行时开始，time不断上涨
	if(cpfh>50){
		flash=~flash;
		cpfh=0;
	}
	STM(time);
}
void timer0_init()
{
	TMOD = 0x01;	
	TH0 = (65536 - 5000) / 256;
	TL0 = (65536 - 5000) % 256;
	EA = 1;
	ET0 = 1;
	TR0 = 1;
}
void display(int num,int Poi){
	P0=0xff;P0=poi[Poi];latch();P0=seven_seg[num];delay(200);
	P0=0xff;P0 = 0X04;latch();P0 = 0xbf|flash;delay(200);
	P0=0xff;P0 = 0X20;latch();P0 = 0xbf|flash;delay(200);
}
void Modedisplay(int num,int Poi){
	P0=0xff;P0=poi[Poi];latch();P0=seven_seg[num]|flash;delay(200);
	P0=0xff;P0 = 0X04;latch();P0 = 0xbf|flash;delay(200);
	P0=0xff;P0 = 0X20;latch();P0 = 0xbf|flash;delay(200);
}
void ShowSec(){
	display(secondA,1);
	display(secondB,0);
}
void ShowMinute(){
	Modedisplay(minuteA,4);
	display(minuteB,3);
}
void ShowHour(){
Modedisplay(hourA,7);
Modedisplay(hourB,6);
}
void modeShowSec(){
	Modedisplay(secondA,1);
	Modedisplay(secondB,0);
}
void modeShowMinute(){
	Modedisplay(minuteA,4);
	Modedisplay(minuteB,3);
}
void modeShowHour(){
display(hourA,7);
display(hourB,6);
}
void key(){
		ShowSec();
		ShowMinute();
		ShowHour();
	if(key1==0){
		start=0;
		mode++;
		if(mode%3==1){modeShowhour();}//小时
		if(mode%3==2){modeShowMinute();}//分钟
		if(mode%3==0){modeShowSec();}//秒
	}
	if(key2==0){}//time++
		if(key3==0){}//time--
	if(key4==0){
	start=1;}//开始时间
}
void main(){
	timer0_init();
	while(1){
		key();
	}
}
