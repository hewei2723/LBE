//���崮��������������˽�P3.5
/*��DS1302��ʼ��*/
void ds1302_init(void)
{
	rst1 = 0;
	scl1 = 0;
	rst1 = 1;
}
/*��DS1302д1�ֽں���*/
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
/*��DS1302��һ�ֽں���*/
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
/*��DS1302��ĳһ��ַдһ�ֽں���*/
void write_ds1302_add_dat(unsigned char add,unsigned char dat)
{
	ds1302_init();
	write_ds1302_onebyte(add);
	write_ds1302_onebyte(dat);
	scl1 = 1;
	rst1 = 0;
}
/*��DS1302��ĳһ��ַ��һ�ֽں���*/
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
/*8421BCD�뵽ʮ����ת��*/
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
void get_ds1302_time(void)													//��ȡ1302��ʱ�����ݣ�ʱ���֡��룩������time1������
{
	unsigned char d;
	d = read_ds1302_add(0x81);												//����
	sec = BCD_DEC_conv(d);													//�õ���	
	d = read_ds1302_add(0x83);												//����
	min = BCD_DEC_conv(d);													//�õ���
	d = read_ds1302_add(0x85);												//��Сʱ
	hour = BCD_DEC_conv(d);													//�õ�Сʱ
	d = read_ds1302_add(0x87);												//����
	date = BCD_DEC_conv(d);													//�õ���
   	d = read_ds1302_add(0x89);												//����
	month = BCD_DEC_conv(d);												//�õ���
	d = read_ds1302_add(0x8b);												//������
	week = BCD_DEC_conv(d);													//�õ�����
	d = read_ds1302_add(0x8d);												//����
	year = BCD_DEC_conv(d);													//�õ���		
}
void time_adj(void)
{
	sec = DEC_BCD_conv(sec);
	min = DEC_BCD_conv(min);	
	hour = DEC_BCD_conv(hour);	
	year = DEC_BCD_conv(year);	
	month = DEC_BCD_conv(month);	
	date = DEC_BCD_conv(date);	
	
	write_ds1302_add_dat(0x8e,0x00);										//д���������Զ�DS1302����
	write_ds1302_add_dat(0x80,sec);										//д�룬30��
	write_ds1302_add_dat(0x82,min);											//д�֣�46��
	write_ds1302_add_dat(0x84,hour);										//дʱ��12ʱ
	write_ds1302_add_dat(0x86,date);										//д�գ�28��
	write_ds1302_add_dat(0x88,month);										//д�£�5�� 
	write_ds1302_add_dat(0x8a,8);										//д���ڣ�������
	write_ds1302_add_dat(0x8c,year);										//д�꣬��20��12��
	write_ds1302_add_dat(0x8e,0x80);										//д����
}