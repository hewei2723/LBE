#include <reg51.h>
sbit LE = P1 ^ 0;
sbit key1 = P2 ^ 0;
sbit key2 = P2 ^ 1;
sbit key3 = P2 ^ 2;
sbit key4 = P2 ^ 3;
int cp = 0, cpfh = 0;
time = 0, flash = 0x00, start = 1, mode = 0;
int secondA, hourA, minuteA, secondB, minuteB, hourB;
int poi[] = {0x80, 0x40, 0x20, 0x10, 0x08, 0x04, 0x02, 0x01};
unsigned char seven_seg[] = {0xc0, 0xf9, 0xa4, 0xb0, 0x99, 0x92, 0x82, 0xf8, 0x80, 0x90};
int sno[] = {1, 1, 6, 0, 1, 0, 2, 2};
void key();
void latch()
{
	LE = 1;
	LE = 0;
}
void delay(int x)
{
	while (x--)
		;
}
void STM(int time)
{
	secondA = (time % 60) / 10;
	secondB = (time % 60) % 10;
	minuteA = (time / 60 % 60) / 10;
	minuteB = (time / 60 % 60) % 10;
	hourA = (time / 3600) / 10;
	hourB = (time / 3600) % 10;
}
void showSno()
{
	int i;
	for (i = 0; i < 8; i++)
	{
		P0 = 0xff;
		P0 = poi[i];
		latch();
		P0 = seven_seg[sno[i]];
		delay(300);
	}
}
void timer0_isr() interrupt 1
{
	TH0 = (65535 - 5000) / 256;
	TL0 = (65535 - 5000) % 256;
	cp++;
	cpfh++;
	if (cp > 25 && start == 1)
	{
		time++;
		cp = 0;
	}
	if (cpfh > 25)
	{
		flash = ~flash;
		cpfh = 0;
	}
	STM(time);
	if (time < 1)
	{
		showSno();
	}
	else
	{
		key();
	}
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
void display(int num, int Poi)
{
	P0 = 0xff;
	P0 = poi[Poi];
	latch();
	P0 = seven_seg[num];
	delay(300);
	P0 = 0xff;
	P0 = 0X04;
	latch();
	P0 = 0xbf | flash;
	delay(100);
	P0 = 0xff;
	P0 = 0X20;
	latch();
	P0 = 0xbf | flash;
	delay(100);
}
void Modedisplay(int num, int Poi)
{
	P0 = 0xff;
	P0 = poi[Poi];
	latch();
	P0 = seven_seg[num] | flash;
	delay(300);
	P0 = 0xff;
	P0 = 0X04;
	latch();
	P0 = 0xbf;
	delay(100);
	P0 = 0xff;
	P0 = 0X20;
	latch();
	P0 = 0xbf;
	delay(100);
}
void ShowTime(int num, int mode) // mode=0 ++ mode=1 +60 mode =2 +3600
{								 // num管理哪一个闪动，mode=0的时候调整模式
	if (num == 0)
	{
		if (mode)
		{
			Modedisplay(secondA, 1);
			Modedisplay(secondB, 0);
		}
		else
		{
			display(secondA, 1);
			display(secondB, 0);
		}
	}
	else if (num == 1)
	{
		if (mode)
		{
			Modedisplay(minuteA, 4);
			Modedisplay(minuteB, 3);
		}
		else
		{
			display(minuteA, 4);
			display(minuteB, 3);
		}
	}
	else if (num == 2)
	{
		if (mode)
		{
			Modedisplay(hourA, 7);
			Modedisplay(hourB, 6);
		}
		else
		{
			display(hourA, 7);
			display(hourB, 6);
		}
	}
}
void changeTime()//确保只在按钮从1变成0的时候触发
{
	int s;
	static int keyS2 = 1, keyS3 = 1; // 按键状态，永远为1
	switch (mode)
	{
	case 0:
		s = 1;
		break;
	case 1:
		s = 60;
		break;
	case 2:
		s = 3600;
		break;
	}
	if (keyS2 == 1 && key2 == 0) // 按键2按下并检测状态
	{
		delay(200);	   // 消抖延时
		if (key2 == 0) // 确认按键仍然按下
		{
			time += s;
			keyS2 = 0; // 置为0，防止重复触发
		}
	}
	else if (key2 == 1) // 按键松开后重置状态
	{
		keyS2 = 1;
	}
	if (keyS3 == 1 && key3 == 0) // 按键3按下并检测状态
	{
		delay(200);	   // 消抖延时
		if (key3 == 0) // 确认按键仍然按下
		{
			time -= s;
			keyS3 = 0; // 置为0，防止重复触发
		}
	}
	else if (key3 == 1) // 按键松开后重置状态
	{
		keyS3 = 1;
	}
}

void key()
{
	int keyL = 1;
	if (start)
	{
		ShowTime(0, 0);
		ShowTime(1, 0);
		ShowTime(2, 0);
	}
	// 按下按钮1，模式变化,start变成0
	if (keyL == 1 && key1 == 0)
	{
		start = 0;
		delay(100);
		// 按一次选择一次模式
		if (key1 == 0)
		{
			mode = (mode + 1) % 3; // 按下一次mode值变化一次，从0，1，2循环变化
		}
		keyL = key1;
		delay(100);
	}
	keyL = 1;
	if (!start)
	{				   // 如果当前是暂停状态
		if (mode == 0) // 秒闪动
		{
			ShowTime(0, 1);
			ShowTime(1, 0);
			ShowTime(2, 0);
			changeTime();
		}
		if (mode == 1) // 分闪动
		{
			ShowTime(0, 0);
			ShowTime(1, 1);
			ShowTime(2, 0);
			changeTime();
		}
		if (mode == 2) // 小时闪动
		{
			ShowTime(0, 0);
			ShowTime(1, 0);
			ShowTime(2, 1);
			changeTime();
		}
	}
	if (key4 == 0)
	{ // 按下按钮4，继续执行
		start = 1;
	}
}
void main()
{
	timer0_init();
	while (1)
		;
}
