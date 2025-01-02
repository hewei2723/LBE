#include <intrins.h>
#define uchar unsigned char
#define uint unsigned int
#define nop _nop_()
sbit sda = P3^6;
sbit scl = P3^7;
sbit DQ = P1^1;
uchar sec, min = 17, hour = 20, year = 24, month = 12, date = 6, week;
sbit rst1 = P3^4;
sbit scl1 = P3^7;
sbit sda1 = P3^5;
unsigned char flash, cp1, cp2, cp3, cp4, cp5, hour_n, min_n;
unsigned char num1, num2, num3, num4, num5, num6;
unsigned char seven_seg[] = {0xc0, 0xf9, 0xa4, 0xb0, 0x99, 0x92, 0x82, 0xf8, 0x80, 0x90};
unsigned char b_s[] = {0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 0x40, 0x80};
unsigned char seg_num[8];
unsigned int temp, temp_dot;
unsigned int cp;
sbit LE = P1^0;

void display(void)
{
    if (cp2 == 0) // 显示学号
    {
        seg_num[7] = seven_seg[2];
        seg_num[6] = seven_seg[2];
        seg_num[5] = seven_seg[0];
        seg_num[4] = seven_seg[1];
        seg_num[3] = seven_seg[0];
        seg_num[2] = seven_seg[6];
        seg_num[1] = seven_seg[1];
        seg_num[0] = seven_seg[1];
    }
    else if (cp2 == 1) // 显示电话号码后三位, 温度
    {
         seg_num[7] = seven_seg[7 ];
        seg_num[6] = seven_seg[7];
        seg_num[5] = seven_seg[9];
        seg_num[4] = 0xff;
        seg_num[3] = 0xff;
        seg_num[2] = seven_seg[temp / 10];
        seg_num[1] = seven_seg[temp % 10] & 0x7f;
        seg_num[0] = seven_seg[temp_dot];
    }
    else if (cp2 == 2) // 显示年月日
    {
        seg_num[0] = seven_seg[date % 10];
        seg_num[1] = seven_seg[date / 10];  
        seg_num[2] = seven_seg[month % 10];
        seg_num[3] = seven_seg[month / 10];     
        seg_num[4] = seven_seg[year % 10];
        seg_num[5] = seven_seg[year / 10];  
        seg_num[6] = seven_seg[0];
        seg_num[7] = seven_seg[2];
    }
    else if (cp2 == 3) // 正常走时
    {
        if (cp3 == 0)
        {
            seg_num[0] = seven_seg[sec % 10];
            seg_num[1] = seven_seg[sec / 10];   
            seg_num[2] = 0xbf | flash;
            seg_num[3] = seven_seg[min % 10];       
            seg_num[4] = seven_seg[min / 10];
            seg_num[5] = 0xbf | flash;  
            seg_num[6] = seven_seg[hour % 10];
            seg_num[7] = seven_seg[hour / 10];
        }
        // 进入时间设置状态
        else if (cp3 == 1)
        {
            seg_num[0] = seven_seg[sec % 10];
            seg_num[1] = seven_seg[sec / 10];   
            seg_num[2] = 0xbf;
            seg_num[3] = seven_seg[min % 10];       
            seg_num[4] = seven_seg[min / 10];
            seg_num[5] = 0xbf;  
            seg_num[6] = seven_seg[hour % 10] | flash;
            seg_num[7] = seven_seg[hour / 10] | flash;
        }
        else if (cp3 == 2)
        {
            seg_num[0] = seven_seg[sec % 10];
            seg_num[1] = seven_seg[sec / 10];   
            seg_num[2] = 0xbf;
            seg_num[3] = seven_seg[min % 10] | flash;       
            seg_num[4] = seven_seg[min / 10] | flash;
            seg_num[5] = 0xbf;  
            seg_num[6] = seven_seg[hour % 10];
            seg_num[7] = seven_seg[hour / 10];
        }
        else if (cp3 == 3)
        {
            seg_num[0] = seven_seg[sec % 10] | flash;
            seg_num[1] = seven_seg[sec / 10] | flash;   
            seg_num[2] = 0xbf;
            seg_num[3] = seven_seg[min % 10];       
            seg_num[4] = seven_seg[min / 10];
            seg_num[5] = 0xbf;  
            seg_num[6] = seven_seg[hour % 10];
            seg_num[7] = seven_seg[hour / 10];
        }
        else if (cp3 == 4)
        {
            seg_num[0] = 0xff;
            seg_num[1] = 0xff;
            seg_num[2] = 0xff;
            seg_num[3] = seven_seg[min_n % 10];
            seg_num[4] = seven_seg[min_n / 10]; 
            seg_num[5] = 0xbf;  
            seg_num[6] = seven_seg[hour_n % 10] | flash;        
            seg_num[7] = seven_seg[hour_n / 10] | flash;
        }
        else if (cp3 == 5)
        {
            seg_num[0] = 0xff;
            seg_num[1] = 0xff;
            seg_num[2] = 0xff;
            seg_num[3] = seven_seg[min_n % 10] | flash;
            seg_num[4] = seven_seg[min_n / 10] | flash; 
            seg_num[5] = 0xbf;  
            seg_num[6] = seven_seg[hour_n % 10];        
            seg_num[7] = seven_seg[hour_n / 10];
        }
    }
}
