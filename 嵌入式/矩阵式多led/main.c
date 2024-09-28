#include <reg51.h>
int x[8]={0x00,0x1c,0x08,0x08,0x08,0x1c,0x00,0x00};
int y[8]={0x80,0x40,0x20,0x10,0x08,0x04,0x02,0x01};
void delay(unsigned int t) {
    while (t--);
}
void main() {
    int i;
    // for (i=0;i<8;i++) {
    //     delay(2000);
    //     P2=x[i];
    //     P0=y[i];
    //     }
	P2=0XFE;
	P0=0XFF;
}