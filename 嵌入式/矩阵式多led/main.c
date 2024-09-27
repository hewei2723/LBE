#include <reg51.h>
sbit x1 = P0^0;
sbit x2 = P0^1;
sbit x3 = P0^2;
sbit x4 = P0^3;
sbit x5 = P0^4;
sbit x6 = P0^5;
// Y
sbit y1 = P2^0;
sbit y2 = P2^1;
sbit y3 = P2^2;
sbit y4 = P2^3;
sbit y5 = P2^4;
sbit y6 = P2^5;
void delay(int x){
while(x--);}
int result[18][2]; 
void I() {
    int index = 0;
    int x, y;

    // I x[1-6] y[6]
    for (x = 1; x <= 6; x++) {
        result[index][0] = x;
        result[index][1] = 6;
        index++;
    }

    // I x[3] y[1-6]
    for (y = 1; y <= 6; y++) {
        result[index][0] = 3;
        result[index][1] = y;
        index++;
    }

    // I x[1-6] y[1]
    for (x = 1; x <= 6; x++) {
        result[index][0] = x;
        result[index][1] = 1;
        index++;
    }
}

void led_on(int x,int y){
	y1=y2=y3=y4=y5=y6=0;
	x1=x2=x3=x4=x5=x6=1;
	switch (x)
    {
    case 1:
        x1=0;
        break;
    case 2:
        x2=0;
        break;
    case 3:
        x3=0;
        break;
    case 4:
        x4=0;
        break;
    case 5:
        x5=0;
        break;
    case 6:
        x6=0;
        break;
    
    default:
        break;
    }
    switch (y)
    {
    case 1:
        y1=1;
        break;
    case 2:
        y2=1;
        break;
    case 3:
        y3=1;
        break;
    case 4:
        y4=1;
        break;
    case 5:
        y5=1;
        break;
    case 6:
        y6=1;
    }
}
int main() {
    int i;
    while (1) {
        I();
        for (i = 0; i < 18; i++) {
            led_on(result[i][0], result[i][1]);
        }
									delay(900);
    }

    return 0;
}