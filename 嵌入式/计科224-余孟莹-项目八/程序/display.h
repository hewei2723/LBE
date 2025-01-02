unsigned char flash,cp1,cp3,cp4;
char hour_n,min_n,sec = 30,min = 30 ,hour = 12;
unsigned char seven_seg[] = {0xc0,0xf9,0xa4,0xb0,0x99,0x92,0x82,0xf8,0x80,0x90};
unsigned char b_s[] = {0x80,0x40,0x20,0x10,0x08,0x04,0x02,0x01};
unsigned char seg_num[8];
unsigned int cp;
sbit LE = P1^0;
void display(void)
{
	if(cp3 == 0)
	{
		seg_num[0] = seven_seg[8];
		seg_num[1] = seven_seg[2];	
		seg_num[2] = seven_seg[4];
		seg_num[3] = seven_seg[0];		
		seg_num[4] = seven_seg[1];
		seg_num[5] = seven_seg[0];	
		seg_num[6] = seven_seg[2];
		seg_num[7] = seven_seg[2];
	}
	if(cp3 == 1)
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
	if(cp3 == 2)
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
	if(cp3 == 3)
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
	if(cp3 == 4)
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
	if(cp3 == 5)
	{
	  	seg_num[0] = seven_seg[min_n % 10];
		seg_num[1] = seven_seg[min_n / 10];	
		seg_num[2] = 0xbf;
		seg_num[3] = seven_seg[hour_n % 10] | flash;		
		seg_num[4] = seven_seg[hour_n / 10] | flash;
		seg_num[5] = 0xbf;	
		seg_num[6] = 0xff;
		seg_num[7] = 0xff;
	}	
	if(cp3 == 6)
	{
	  	seg_num[0] = seven_seg[min_n % 10] | flash;
		seg_num[1] = seven_seg[min_n / 10] | flash;	
		seg_num[2] = 0xbf;
		seg_num[3] = seven_seg[hour_n % 10];		
		seg_num[4] = seven_seg[hour_n / 10];
		seg_num[5] = 0xbf;	
		seg_num[6] = 0xff;
		seg_num[7] = 0xff;
	}				
}