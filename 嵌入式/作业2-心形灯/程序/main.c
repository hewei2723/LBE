#include <reg51.h>
int led1[9] = {0Xfe, 0xfd, 0xfb, 0xf7, 0xef, 0xdf, 0xbf, 0x7f, 0xff};
int led2[8] = {0Xfc, 0xf9, 0xf3, 0xe7, 0xcf, 0x9f, 0x3f, 0xff};
int i, j;
void delay(unsigned int x)
{
	while (x--)
		;
}
one()
{
	for (i = 0; i <= 3; i++)
	{
		switch (i)
		{
		case 0:
			for (j = 0; j < 8; j++)
			{
				P0 = led1[j];
				delay(5000);
				P0 = led1[8];
			}
			P0 = led1[8];
			break;
		case 1:
			for (j = 0; j < 8; j++)
			{
				P1 = led1[j];
				delay(5000);
				P1 = led1[8];
			}
			break;
		case 2:
			for (j = 0; j < 8; j++)
			{
				P2 = led1[j];
				delay(5000);
				P2 = led1[8];
			}
			break;
		case 3:
			for (j = 0; j < 8; j++)
			{
				P3 = led1[j];
				delay(5000);
				P3 = led1[8];
			}
			break;
		}
	}
}
two()
{
	for (i = 0; i <= 3; i++)
	{
		switch (i)
		{
		case 0:
			for (j = 0; j < 8; j++)
			{
				P0 = led2[j];
				delay(5000);
				P0 = led2[7];
			}
			P0 = led2[7];
			break;
		case 1:
			for (j = 0; j < 7; j++)
			{
				P1 = led2[j];
				delay(5000);
				P1 = led2[7];
			}
			P1 = led2[7];
			break;
		case 2:
			for (j = 0; j < 7; j++)
			{
				P2 = led2[j];
				delay(5000);
				P2 = led2[7];
			}
			P2 = led2[7];
			break;
		case 3:
			for (j = 0; j < 7; j++)
			{
				P3 = led2[j];
				delay(5000);
				P3 = led2[7];
			}
			P3 = led2[7];
			break;
		}
	}
}
void main()
{
	one();
	two();
}
