#include <reg51.h>
#include <ds18b20.h>  
unsigned char seven_seg[] = {0xc0, 0xf9, 0xa4, 0xb0, 0x99, 0x92, 0x82, 0xf8, 0x80, 0x90};  
unsigned char bit_scan[] = {0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 0x40, 0x80}; 
unsigned char pnum[]={1,5,7,3,8,2,8,0};
unsigned char display_num[8];  
unsigned int temp1,temp2,temp_num;  
unsigned char cp0,cp1;  
sbit le = P1^0;  
void display_dat(void) {  
    display_num[0] = 0xff; 
    display_num[1] = 0xff;  
    display_num[2] = 0xff;  
    display_num[3] = 0xff;  
    if ((temp_dat & 0xf800) < 0xf800)
			{  
        temp_num = temp_dat & 0x0fff; 
				temp2 = (temp_num & 0x000f) * 0.625 ;  
        temp1 = temp_num >> 4;  
        display_num[4] = 0xff;  
        display_num[5] = seven_seg[temp1 / 10];  
        display_num[6] = seven_seg[temp1 % 10] & 0x7f; 
        display_num[7] = seven_seg[temp2]; 			
    } else {
			  temp_num = ~temp_dat + 1; 
        temp2 = (temp_num & 0x000f) * 0.0625 + 0.5; 
				temp1 = temp_num >> 4;  
        display_num[4] = 0xbf;  
        display_num[5] = seven_seg[temp1 / 10];  
        display_num[6] = seven_seg[temp1 % 10] & 0x7f;  
        display_num[7] = seven_seg[temp2];  
    }
}
void latch(void) {  le = 1; le = 0;}
void timer0_isr(void) interrupt 1 {  
    TH0 = (65536 - 2000) / 256;
    TL0 = (65536 - 2000) % 256;
	  P0 = 0xff;  
    P0 = bit_scan[cp1];latch();P0 = display_num[cp1];
    cp1++;
	  if (cp1 >= 8) cp1= 0;
    cp0++;
}
void timer0_init(void) {  
    TMOD = 0x01;
    TH0 = (65536 - 2000) / 256;
    TL0 = (65536 - 2000) % 256;
    EA = 1;
    ET0 = 1;
    TR0 = 1;
}
void show(){
	int i;
	for(i=0;i<8;i++){
		P0=0xff;P0=bit_scan[i];latch();P0=seven_seg[pnum[i]];delay(500);
	}
}
void main(void) {
//int x=50;	
//	do{
//		show();
//		x--;
//	}
//	while(x>0);
	timer0_init();
    while (1) {
        display_dat();  
        if (cp0 == 200) { 
            cp0 = 0;
            read_temp_ds18b20();  
        }
    }	
}
