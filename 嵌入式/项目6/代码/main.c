#include <reg51.h>
int seg[10] = {0xc0, 0xf9, 0xa4, 0xb0, 0x99, 0x92, 0x82, 0xf8, 0x80, 0x90};
int ptwo[8] = {0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 0x40, 0x80};
int i=0,hours,minutes,second;
void delay(int x)
{
	while (x--)
		;
}
void timer_init(void)
{
	TMOD = 0x01;
	TL0 = (65535 - 2000) % 256;
	TH0 = (65535 - 2000) / 256;
	EA = 1;
	ET0 = 1;
}//����
void timer0_isr(void) interrupt 1
{
	TL0 = 0X78;
	TH0 = 0Xec;
	cp++;
	if (cp = > 200)
	{
		cp = 0;
		i++;
		if(i==60*60*24){
			i=0;
		}//����24Сʱ����
	}
	hours=i/3600;
	minutes=(i%3600)/60;
	second=i%60;
	//���֮��i�Ƕ��پ͹��˶�����
	//�������ʾʱ��Ĵ���
	
}
int showStu()
{
	int stu[8] = {2, 2, 0, 1, 0, 6, 1, 1};
	int i;
	for (i = 0; i < 8; i++)
	{
		P0 = seg[stu[i]];
		P2 = ptwo[i];
		delay(110);
		P0 = 0Xff;
	}
}
void main()
{
	showStu();
	time0_init();
}