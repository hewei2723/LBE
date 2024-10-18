#include <reg51.h>
unsigned char key, seg[] = {0xc0, 0xf9, 0xa4, 0xb0, 0x99, 0x92, 0x82, 0xf8, 0x80, 0x90, 0x88, 0x83, 0xc6, 0xa1, 0x86, 0x8e};  

void delay(int x) {
    while (x--);
}

void key(void) {
    P2 = 0xef;
    if (P2 == 0xee) key = 0;
    if (P2 == 0xed) key = 1;
    if (P2 == 0xeb) key = 2;
    if (P2 == 0xe7) key = 3;
    P2 = 0xdf;
    if (P2 == 0xde) key = 4;
    if (P2 == 0xdd) key = 5;
    if (P2 == 0xdb) key = 6;
    if (P2 == 0xd7) key = 7;
    P2 = 0xbf;
    if (P2 == 0xbe) key = 8;
    if (P2 == 0xbd) key = 9;
    if (P2 == 0xbb) key = 10;  
    if (P2 == 0xb7) key = 11; 
    P2 = 0x7f;
    if (P2 == 0x7e) key = 12; 
    if (P2 == 0x7d) key = 13;  
    if (P2 == 0x7b) key = 14;  
    if (P2 == 0x77) key = 15;  
}
void main(void) {
    while (1) {
        P3 = 0x01; 
        P0 = seg[key / 10];  
        delay(500);   
        P3 = 0x02; 
        P0 = seg[key % 10];  
        delay(500);
        key();  
    }
}