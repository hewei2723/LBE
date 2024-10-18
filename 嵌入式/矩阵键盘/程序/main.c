#include <reg51.h>
int seg[] = {0xc0, 0xf9, 0xa4, 0xb0, 0x99, 0x92, 0x82, 0xf8, 0x80, 0x90};
int key[] = {0x8, 0x4, 0x2, 0x1};
sbit x1 = P2 ^ 0;
sbit x2 = P2 ^ 1;
sbit x3 = P2 ^ 2;
sbit x4 = P2 ^ 3;
sbit seg1 = P1 ^ 0;
sbit seg2 = P1 ^ 1;
int delay(int x)
{
	while (x--)
		;
}
void show(unsigned int num)
{
	int a, b, c, d;
	d = num / 1000;
	c = (num % 1000) / 100;
	b = (num % 100) / 10;
	a = num % 10;
	while (1)
	{
		seg1 = 1;
		P0 = seg[d];
		delay(200);
		seg1 = 0;
		P2 = 0Xff;
		seg2 = 1;
		P1 = seg[c];
		delay(200);
		seg2 = 0;
		P2 = 0Xff;
	} 
	delay(5000);
}
int main()
{
	int i, b;
	int x, y;
	while (1)
	{
		for (i = 0; i < 3; i++)
		{
			P2 = key[i];
			delay(500);
			if (x1 == 0)
			{
				x = 1;
				y = i + 1;
				b = x * 10 + y;
				show(b);
			}
			else if (x2 == 0)
			{
				x = 2;
				y = i + 1;
				b = x * 10 + y;
				show(b);
			}
			else if (x3 == 0)
			{
				x = 3;
				y = i + 1;
				b = x * 10 + y;
				show(b);
			}
			else if (x4 == 0)
			{
				x = 4;
				y = i + 1;
				b = x * 10 + y;
				show(b);
			}
			delay(500);
		}
	}
}