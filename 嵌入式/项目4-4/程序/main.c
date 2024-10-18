#include <reg51.h>
unsigned char KEY_num, seven_seg[] = {0xc0, 0xf9, 0xa4, 0xb0, 0x99, 0x92, 0x82, 0xf8, 0x80, 0x90, 0x88, 0x83, 0xc6, 0xa1, 0x86, 0x8e};  

void delay(unsigned int x) {
    while (x--);
}

void key(void) {
    // 扫描第一列
    P2 = 0xef;  // 1110 1111
    if (P2 == 0xee) KEY_num = 0;
    if (P2 == 0xed) KEY_num = 1;
    if (P2 == 0xeb) KEY_num = 2;
    if (P2 == 0xe7) KEY_num = 3;

    // 扫描第二列
    P2 = 0xdf;  // 1101 1111
    if (P2 == 0xde) KEY_num = 4;
    if (P2 == 0xdd) KEY_num = 5;
    if (P2 == 0xdb) KEY_num = 6;
    if (P2 == 0xd7) KEY_num = 7;

    // 扫描第三列
    P2 = 0xbf;  // 1011 1111
    if (P2 == 0xbe) KEY_num = 8;
    if (P2 == 0xbd) KEY_num = 9;
    if (P2 == 0xbb) KEY_num = 10;  
    if (P2 == 0xb7) KEY_num = 11; 
    // 扫描第四列
    P2 = 0x7f;  // 0111 1111
    if (P2 == 0x7e) KEY_num = 12; 
    if (P2 == 0x7d) KEY_num = 13;  
    if (P2 == 0x7b) KEY_num = 14;  
    if (P2 == 0x77) KEY_num = 15;  
}

void main(void) {
    while (1) {
        P3 = 0x01; 
        P0 = seven_seg[KEY_num / 10];  
        delay(500);
        
        P3 = 0x02; 
        P0 = seven_seg[KEY_num % 10];  
        delay(500);
        
        key();  
    }
}
