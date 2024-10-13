#include <REG51.H>
sbit led1 = P0 ^ 0;
sbit led2 = P0 ^ 1;
sbit key1 = P2 ^ 0;
sbit key2 = P2 ^ 1;
sbit key3 = P2 ^ 2;
sbit key4 = P2 ^ 3;
int delay(unsigned int t)
{
	while (t--)
		;
}
int main()
{
	while (1)
	{
		if (key1 ==0)
		{
				led1 ==0;
		}
	}
}