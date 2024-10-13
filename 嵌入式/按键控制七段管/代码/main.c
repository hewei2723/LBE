#include <reg51.h>
int gnd[] = {0xc0, 0xf9, 0xa4, 0xb0, 0x99, 0x92, 0x82, 0xf8, 0x80, 0x90};
sbit key4 = P0 ^ 7;
sbit key3 = P2 ^ 7;
sbit key2 = P3 ^ 7;
sbit key1 = P1 ^ 7;
void delay(unsigned int x)
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
    P0 = gnd[d];
    P2 = gnd[c];
    P3 = gnd[b];
    P1 = gnd[a];
    delay(5000);
}
void main()
{
    int i = 611;
    while (1)
    {
        show(i);
        if (key1 == 0)
        {
            delay(13000);
            while (key1 == 0)
            {
                show(i = i + 1);
            }
        }
         if (key2 == 0)
        {
            delay(14000);
            while (key2 == 0)
            {
                show(i = i + 10);
            }
        }
		if (key3 == 0)
        {
            delay(14000);
            while (key3 == 0)
            {
			while(i<779){
			show(i++);}
			}
            }
        }
    }
