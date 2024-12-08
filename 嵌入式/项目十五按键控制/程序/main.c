//main.c
#include<reg51.h>
#include<ds1302.c>
#include<display.c>
#include<key.c>
sbit LED = 	P1^7;
void t0_isr(void) interrupt 1
{
	TH0 = (65536 - 2000) / 256;
	TL0 = (65536 - 2000) % 256;
	cp++;
	if(cp >= 250){cp = 0;cp4++;flash = ~flash;}
	if(cp4 >= 4){cp4 = 0;cp2++;if(cp2 >= 6)cp2 = 6;}
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
	time_adj();
	while(1)
	{
		display();
		get_ds1302_time();
		key();
		if(hour == hour_n && min == min_n)LED = 0;
		else LED = 1;
	}
}