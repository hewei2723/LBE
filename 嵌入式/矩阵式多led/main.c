
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
//这里放字模
//I x[1-6]y[6]
//I x[3]y[1-6]
//I x[1-6]y[1]
void delay(unsigned int t)
{
    while (t--);
}
//当y为高 x为低时，灯亮
void turn_on_led(int row, int col) {
    x1 = x2 = x3 = x4 = x5 = x6 = 1;
    y1 = y2 = y3 = y4 = y5 = y6 = 0;
    switch(row) {
        case 1: x1 = 0; break;
        case 2: x2 = 0; break;
        case 3: x3 = 0; break;
        case 4: x4 = 0; break;
        case 5: x5 = 0; break;
        case 6: x6 = 0; break;
    }
    switch(col) {
        case 1: y1 = 1; break;
        case 2: y2 = 1; break;
        case 3: y3 = 1; break;
        case 4: y4 = 1; break;
        case 5: y5 = 1; break;
        case 6: y6 = 1; break;
    }
}
//当x=y时不亮
void turn_off_led(int row, int col) {
    switch(row) {
        case 1: x1 = 1; break;
        case 2: x2 = 1; break;
        case 3: x3 = 1; break;
        case 4: x4 = 1; break;
        case 5: x5 = 1; break;
        case 6: x6 = 1; break;
    }
    switch(col) {
        case 1: y1 = 0; break;
        case 2: y2 = 0; break;
        case 3: y3 = 0; break;
        case 4: y4 = 0; break;
        case 5: y5 = 0; break;
    }
}
void main() {
    while (1) {
        turn_on_led(1, 2);  // Turn on the LED at (x1, y1)
        delay(1000);       // Wait for a while
        turn_off_led(1, 2); // Turn off the LED at (x1, y1)
    }
}
