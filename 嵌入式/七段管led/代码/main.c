#include <reg51.h>
int gnd[] = {0xc0, 0xf9, 0xa4, 0xb0, 0x99, 0x92, 0x82,0xf8, 0x80, 0x90};
sbit SEG1 = P0;
sbit SEG2 = P2;
sbit SEG3 = P3;
sbit SEG4 = P1;
void delay(unsigned int x) {
    while (x--);
}
void dis(unsigned int num) {
    int unit, ten, hundred, thousand;
    thousand = num / 1000;
    hundred = (num % 1000) / 100;
    ten = (num % 100) / 10;
    unit = num % 10;
    SEG1 = gnd[thousand];
		delay(50000);
}
void main() {
    unsigned int i;
    dis(1);
}
