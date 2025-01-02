#include<reg51.h>
#include<display.h>
#include<key.h>
unsigned char ck;
sbit led  = P1^7;
void t0_isr(void) interrupt 1
{
	TH0 = (65536 - 2000) / 256;
	TL0 = (65536 - 2000) % 256;
	cp++;
	if(cp >= 250){cp = 0;ck++;flash = ~flash;}
	if(ck >= 2){ck = 0;sec++;cp4++;}
	if(sec >= 60){sec = 0;min++;}
	if(min >= 60){min = 0;hour++;}
	if(hour >= 24)hour = 0;
	P0 = 0xff;
	P0 = b_s[cp1];LE = 1;LE = 0;P0 = seg_num[cp1];//ÏÔÊ¾³ÌÐò
	cp1++;
	if(cp1 >= 8)cp1 = 0;
}
void t0_init(void)
{
	TMOD = 0x01;
	TH0 = (65536 - 2000) / 256;
	TL0 = (65536 - 2000) % 256;
	EA = 1;
	ET0 = 1;
	TR0 = 1;
}
void main(void)
{
	t0_init();
	cp3 = 0;
	display();
	while(cp4 <= 2);
	cp3 = 1;
	cp4 = 0; 	
	while(1)
	{
		display();
		key();
		if(hour_n == hour && min_n == min)led = 0;
		else led = 1;
	}
}