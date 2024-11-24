sbit DQ=P1^1;	//定义DS18b20的管脚

/*****延时子程序*****/
void delay(unsigned int t)
{
	for(;t>0;t--);
}


/*****初始化DS18B20*****/
unsigned char Init_DS18B20(void)
{
  unsigned char x=0;
  DQ = 1;      //DQ复位
  delay(8);    //稍做延时
  DQ = 0;      //单片机将DQ拉低
  delay(80);   //精确延时，大于480us
  DQ = 1;      //拉高总线
  delay(8);
  x = DQ;      //稍做延时后，如果x=0则初始化成功，x=1则初始化失败
  delay(4);
  return x;
}

/*****读一个字节*****/
unsigned char ReadOneChar(void)
{
  unsigned char i=0;
  unsigned char dat = 0;
  for (i=8;i>0;i--)
  {
    DQ = 0;     // 给脉冲信号
    dat>>=1;
    DQ = 1;     // 给脉冲信号
    if(DQ)
    	dat|=0x80;
	delay(4);
  }
  return(dat);
}

/*****写一个字节*****/
void WriteOneChar(unsigned char dat)
{
  unsigned char i=0;
  for (i=8; i>0; i--)
  {
    DQ = 0;
    DQ = dat&0x01;
	delay(4);
    DQ = 1;
    dat>>=1;
  }
  delay(4);
}

/*****读取温度*****/
int ReadTemperature(void)
{
  	unsigned char a=0;
  	unsigned char b=0;
  	unsigned int t=0;
		unsigned int Real_temp;
  	t=Init_DS18B20();
  	if(t) return Real_temp;
  	WriteOneChar(0xCC);  //跳过读序号列号的操作
  	WriteOneChar(0x44);  //启动温度转换
  	t=Init_DS18B20();
  	if(t) return Real_temp;
  	WriteOneChar(0xCC);  //跳过读序号列号的操作
  	WriteOneChar(0xBE);  //读取温度寄存器
  	a=ReadOneChar();     //读低8位
  	b=ReadOneChar();     //读高8位
  	t=b;
  	t<<=8;
  	t=t|a;
  	if(t<=0||t>0x900) 
		return Real_temp;
		t=t*0.625+0.5;
  	return(t);
}

