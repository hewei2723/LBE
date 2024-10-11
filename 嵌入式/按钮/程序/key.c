#include "reg51.h"
sbit key = P0^7;
sbit led= P0^0;
void delay(unsigned int t){
    while (x--);
}
int main(void){
    if key == 0{
        delay(200);
        while (key==0)
        {              
        led = 1;
        }

    }
}