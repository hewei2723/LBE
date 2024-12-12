//定义串行数据输入输出端接P3.5
/*对DS1302初始化*/
void ds1302_init(void)
{
	rst1 = 0;
	scl1 = 0;
	rst1 = 1;
}
/*对DS1302写1字节函数*/
void write_ds1302_onebyte(unsigned char dat)	   
{
	unsigned char i;
	for(i = 0;i < 8;i++)
	{
		sda1 = (bit)(dat & 0x01);
		scl1 = 0;
		scl1 = 1;
		dat = dat >> 1;
	}
}
/*从DS1302读一字节函数*/
uchar read_ds1302_onebyte(void)		
{
	unsigned char i,dat;
	for(i = 0;i < 8;i++)
	{
		scl1 = 1;
		scl1 = 0;
		dat = dat >> 1;
		if(sda1)dat = dat | 0x80;
	}
	return(dat);	
}
/*对DS1302的某一地址写一字节函数*/
void write_ds1302_add_dat(unsigned char add,unsigned char dat)
{
	ds1302_init();
	write_ds1302_onebyte(add);
	write_ds1302_onebyte(dat);
	scl1 = 1;
	rst1 = 0;
}
/*从DS1302的某一地址读一字节函数*/
uchar read_ds1302_add(unsigned char add)									
{
   unsigned char dat_temp;
	ds1302_init();
	write_ds1302_onebyte(add);
	dat_temp = read_ds1302_onebyte();
	scl1 = 1;
	rst1 = 0;
	return(dat_temp);
}
/*8421BCD码到十进制转换*/
uchar BCD_DEC_conv(unsigned char x)
{
	unsigned char dec;
	dec =  0x0f & x;
	x = x >> 4;
	dec	= dec + x * 10;
	return(dec);
}
uchar DEC_BCD_conv(unsigned char x)
{
	unsigned char bcd;
	bcd =  x % 10;
	x = x / 10;
	x = x << 4;
	bcd	= bcd | x ;
	return(bcd);
}
void get_ds1302_time(void)													//获取1302的时间数据（时、分、秒），存入time1数组中
{
	unsigned char d;
	d = read_ds1302_add(0x81);												//读秒
	sec = BCD_DEC_conv(d);													//得到秒	
	d = read_ds1302_add(0x83);												//读分
	min = BCD_DEC_conv(d);													//得到分
	d = read_ds1302_add(0x85);												//读小时
	hour = BCD_DEC_conv(d);													//得到小时
	d = read_ds1302_add(0x87);												//读日
	date = BCD_DEC_conv(d);													//得到日
   	d = read_ds1302_add(0x89);												//读月
	month = BCD_DEC_conv(d);												//得到月
	d = read_ds1302_add(0x8b);												//读星期
	week = BCD_DEC_conv(d);													//得到星期
	d = read_ds1302_add(0x8d);												//读年
	year = BCD_DEC_conv(d);													//得到年		
}
void time_adj(void)
{
	sec = DEC_BCD_conv(sec);
	min = DEC_BCD_conv(min);	
	hour = DEC_BCD_conv(hour);	
	year = DEC_BCD_conv(year);	
	month = DEC_BCD_conv(month);	
	date = DEC_BCD_conv(date);	
	
	write_ds1302_add_dat(0x8e,0x00);										//写操作，可以对DS1302调整
	write_ds1302_add_dat(0x80,sec);										//写秒，30秒
	write_ds1302_add_dat(0x82,min);											//写分，46分
	write_ds1302_add_dat(0x84,hour);										//写时，12时
	write_ds1302_add_dat(0x86,date);										//写日，28日
	write_ds1302_add_dat(0x88,month);										//写月，5月 
	write_ds1302_add_dat(0x8a,8);										//写星期，星期三
	write_ds1302_add_dat(0x8c,year);										//写年，（20）12年
	write_ds1302_add_dat(0x8e,0x80);										//写保护
}