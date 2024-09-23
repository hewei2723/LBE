#include <reg51.h>
int led[8] = {0Xfe, 0xfd, 0xfb, 0xf7, 0xef, 0xdf, 0xbf, 0x7f};
void delay(unsigned int x){
	while(x--);
}
void main() {
    int *l;
    l = &led[0];
    while (l < &led[8]) { 
        P0 = *l;
						delay(5000);
				P1=*l;
						delay(5000);
			P2=*l;
						delay(5000);
			P3=*l;
			delay(5000);
        l++;
    }
}
