/********初始化函数********/
void Init_DS18B20(void)											
{
	unsigned char x = 255;
	DQ = 1;														//先让DQ置1
	DQ = 0;														//单片机将DQ拉低
	delay(80);													//延时480-960us
	DQ = 1;														//释放总线
	while(DQ && x--);											//等待返回的低电平响应 如果没有响应，则做适量延时自动往下执行
	delay(20);
}
/********从DS18B20中读一个字节********/
uchar Read_OneChar(void)										//基本操作函数2
{
	uchar i = 0;
	uchar dat = 0;
	DQ = 1;
	for (i = 8;i > 0;i--)
	{
  		DQ = 0;													//发送启动信号
  		dat >>= 1;									  	
  		DQ = 1;													//释放总线
  		if(DQ)dat = dat | 0x80;													//判断总线是否为高电平 													//如果是高电平，则把dat的最高位置1，如果不是，默认置0
  		delay(10);
	}
	return(dat);
}
/********向18B20中写一个字节********/
void Write_OneChar(uchar dat)									//基本操作函数3
{
	uchar i = 0;
	DQ = 1;
	for (i = 8;i > 0; i--)
	{
		DQ = 0;
		DQ = (bit)(dat & 0x01);										//取dat的最低位
		delay(10);
		DQ = 1;
		dat = dat >> 1;
	}
	delay(8);
}
/********读取温度********/
uint Read_Temperature(void)									//应用操作函数1
{
	uint i,j;
	Init_DS18B20();
	Write_OneChar(0xcc);										// 跳过读序号列号的操作
	Write_OneChar(0x44);  	//启动温度转换
										
	Init_DS18B20();
	Write_OneChar(0xcc);										//跳过读序号列号的操作
	Write_OneChar(0xbe);										//读取温度寄存器等（共可读9个寄存器） 前两个就是温度
	
	i = Read_OneChar();											//读取温度值低8位
	j = Read_OneChar();											//读取温度值高8位
	j = j << 8;													//高8位左移										
    i = i | j;													//合成16位温度值
	return(i);
}