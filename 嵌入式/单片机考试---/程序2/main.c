#include <reg51.h>
#include <display.h>
#include <ds1302.c>
#include <intrins.h>
#include <at24c04.h>
#include <ds18b20.h>
#include <key.h>
sbit LED = P1^7;
void t0_isr(void) interrupt 1
{
    TH0 = (65536 - 2000) / 256;  // 检查这个值是否正确
    TL0 = (65536 - 2000) % 256;
    cp++;
    if (cp >= 250) { cp = 0; cp4++; flash = ~flash; cp5++; }
    if (cp4 >= 2) { cp4 = 0; cp2++; if (cp2 >= 4) cp2 = 3; }
    P0 = 0xff;
    P0 = b_s[cp1]; LE = 1; LE = 0; P0 = seg_num[cp1];
    cp1++;
    if (cp1 >= 8) cp1 = 0;
}

void t0_init(void)
{
    TMOD = 0x01;
    TH0 = (65536 - 2000) / 256;  // 检查这个值是否正确
    TL0 = (65536 - 2000) % 256;
    EA = 1;
    ET0 = 1;
    TR0 = 1;
}

void main(void)
{
    init_2404();
    Read_Temperature();
    delay(30000);
    write_add_dat_2404(1, 22);
    delay(300);
    write_add_dat_2404(2, 01);
    delay(300);
    write_add_dat_2404(3, 06);
    delay(300);
    write_add_dat_2404(4, 11);
    delay(300);
    write_add_dat_2404(5, 7);
    delay(300);
    write_add_dat_2404(6, 79);
    delay(300);
    num1 = read_add_dat_2404(1);
    delay(3000);
    num2 = read_add_dat_2404(2);
    delay(3000);
    num3 = read_add_dat_2404(3);
    delay(3000);
    num4 = read_add_dat_2404(4);
    delay(3000);
    num5 = read_add_dat_2404(5);
    delay(3000);
    num6 = read_add_dat_2404(6);
    delay(3000);
    
    t0_init();
    
    while (1)
    {
        if (cp5 >= 2)
        {
            cp5 = 0;
            temp = Read_Temperature();
            temp_dot = temp & 0x000f;
            temp_dot = temp_dot * 0.625;
            temp = temp >> 4;      
        }
        display();
        get_ds1302_time();
        key();
        
        if (hour == hour_n && min == min_n)
            LED = 0;
        else
            LED = 1;
    }
}
