//dispaly.c
#include <intrins.h>					  //库函数的头文件
#define uchar unsigned char								//把 unsigned char 宏定义为 uchar
#define uint unsigned int	
#define nop _nop_()
sbit sda = P3^6;						  //将sda接P3.6端口
sbit scl = P3^7;						  //将scl接P3.7端口
sbit DQ = P1^1;													//定义单片机的P2.7与DS18B20数据端口连接在一起  
//把 unsigned int 宏定义为 uint
uchar sec,min = 17,hour = 20,year = 24,month = 12,date = 6,week;
sbit rst1 = P3^4;										//定义复位/片选线接P3.4
sbit scl1 = P3^7;										//定义串行时钟引脚接P3.7
sbit sda1 = P3^5;
unsigned char flash,cp1,cp2,cp3,cp4,cp5,hour_n,min_n;
unsigned char num1,num2,num3,num4,num5,num6;
unsigned char seven_seg[] = {0xc0,0xf9,0xa4,0xb0,0x99,0x92,0x82,0xf8,0x80,0x90};
unsigned char b_s[] = {0x01,0x02,0x04,0x08,0x10,0x20,0x40,0x80};
unsigned char seg_num[8];
unsigned int temp,temp_dot;
unsigned int cp;
sbit LE = P1^0;
#include<at24c04.h>
#include<ds18b20.h>
#include<ds1302.h>
#include<key.h>
void display(void)
{
    if(cp2 == 0) // 显示学号
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
    if(cp2 == 1) // 显示电话号码后三位,温度
    {
        seg_num[7] = seven_seg[9 ];
        seg_num[6] = seven_seg[1];
        seg_num[5] = seven_seg[0];
        seg_num[7] = seven_seg[2];
        seg_num[6] = seven_seg[2];
        seg_num[5] = seven_seg[0];
        seg_num[4] = seven_seg[1];
        seg_num[3] = seven_seg[0];
        seg_num[2] = seven_seg[6];
        seg_num[1] = seven_seg[1];
        seg_num[0] = seven_seg[1];
    }
    if(cp2 == 1) // 显示电话号码后三位,温度
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
  if(cp2 == 2) // 显示年月日
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
    if(cp2 == 3 && cp3 == 0)//正常走时
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
	//进入时间设置状态			
	if(cp3 == 1) 
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
	if(cp3 == 2) 
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
	if(cp3 == 3) 
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
	if(cp3 == 4)
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
	if(cp3 == 5)
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
