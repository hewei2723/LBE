//display.c

unsigned char flash,cp1,cp2,cp3,cp4,hour_n,min_n;
unsigned char seven_seg[] = {0xc0,0xf9,0xa4,0xb0,0x99,0x92,0x82,0xf8,0x80,0x90};
unsigned char b_s[] = {0x80,0x40,0x20,0x10,0x08,0x04,0x02,0x01};
unsigned char seg_num[8];
unsigned int cp;
sbit LE = P1^0;
void display(void)
{
	//显示手机号前八位
	if(cp2 == 0)
	{
		seg_num[0] = seven_seg[4];
		seg_num[1] = seven_seg[3];	
		seg_num[2] = seven_seg[6];
		seg_num[3] = seven_seg[4];		
		seg_num[4] = seven_seg[4];
		seg_num[5] = seven_seg[3];	
		seg_num[6] = seven_seg[7];
		seg_num[7] = seven_seg[1];
	}
	//显示手机号后三位
	if(cp2 == 1)
	{
		seg_num[0] = 0xff;
		seg_num[1] = 0xff;	
		seg_num[2] = 0xff;
		seg_num[3] = 0xff;	
		seg_num[4] = 0xff;
		seg_num[5] = seven_seg[8];	
		seg_num[6] = seven_seg[5];
		seg_num[7] = seven_seg[2];
	}
	//显示学号前八位
	if(cp2 == 3)
	{
		seg_num[0] = seven_seg[4];
		seg_num[1] = seven_seg[0];	
		seg_num[2] = seven_seg[1];
		seg_num[3] = seven_seg[0];		
		seg_num[4] = seven_seg[2];
		seg_num[5] = seven_seg[2];	
		seg_num[6] = seven_seg[0];
		seg_num[7] = seven_seg[2];
	}
	//显示学号后两位
	if(cp2 == 4)
	{
		seg_num[0] = 0xff;
		seg_num[1] = 0xff;	
		seg_num[2] = 0xff;
		seg_num[3] = 0xff;	
		seg_num[4] = 0xff;
		seg_num[5] = 0xff;	
		seg_num[6] = seven_seg[8];
		seg_num[7] = seven_seg[2];
	}
	if(cp2 == 5)
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
	if(cp2 == 6 && cp3 == 0)//正常走时
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
		seg_num[0] = seven_seg[date % 10];
		seg_num[1] = seven_seg[date / 10];	
		seg_num[2] = 0xbf;
		seg_num[3] = seven_seg[month % 10];		
		seg_num[4] = seven_seg[month / 10];
		seg_num[5] = 0xbf;	
		seg_num[6] = seven_seg[year % 10] | flash;
		seg_num[7] = seven_seg[year / 10] | flash;
	}
	if(cp3 == 2)
	{
		seg_num[0] = seven_seg[date % 10];
		seg_num[1] = seven_seg[date / 10];	
		seg_num[2] = 0xbf;
		seg_num[3] = seven_seg[month % 10] | flash;		
		seg_num[4] = seven_seg[month / 10] | flash;
		seg_num[5] = 0xbf;	
		seg_num[6] = seven_seg[year % 10];
		seg_num[7] = seven_seg[year / 10];
	}
	if(cp3 == 3)
	{
		seg_num[0] = seven_seg[date % 10] | flash;
		seg_num[1] = seven_seg[date / 10] | flash;	
		seg_num[2] = 0xbf;
		seg_num[3] = seven_seg[month % 10];		
		seg_num[4] = seven_seg[month / 10];
		seg_num[5] = 0xbf;	
		seg_num[6] = seven_seg[year % 10];
		seg_num[7] = seven_seg[year / 10];
	}
	if(cp3 == 4) 
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
	if(cp3 == 5) 
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
	if(cp3 == 6) 
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
	if(cp3 == 7)
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
	if(cp3 == 8)
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