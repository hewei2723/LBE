/********��ʼ������********/
void Init_DS18B20(void)											
{
	unsigned char x = 255;
	DQ = 1;														//����DQ��1
	DQ = 0;														//��Ƭ����DQ����
	delay(80);													//��ʱ480-960us
	DQ = 1;														//�ͷ�����
	while(DQ && x--);											//�ȴ����صĵ͵�ƽ��Ӧ ���û����Ӧ������������ʱ�Զ�����ִ��
	delay(20);
}
/********��DS18B20�ж�һ���ֽ�********/
uchar Read_OneChar(void)										//������������2
{
	uchar i = 0;
	uchar dat = 0;
	DQ = 1;
	for (i = 8;i > 0;i--)
	{
  		DQ = 0;													//���������ź�
  		dat >>= 1;									  	
  		DQ = 1;													//�ͷ�����
  		if(DQ)dat = dat | 0x80;													//�ж������Ƿ�Ϊ�ߵ�ƽ 													//����Ǹߵ�ƽ�����dat�����λ��1��������ǣ�Ĭ����0
  		delay(10);
	}
	return(dat);
}
/********��18B20��дһ���ֽ�********/
void Write_OneChar(uchar dat)									//������������3
{
	uchar i = 0;
	DQ = 1;
	for (i = 8;i > 0; i--)
	{
		DQ = 0;
		DQ = (bit)(dat & 0x01);										//ȡdat�����λ
		delay(10);
		DQ = 1;
		dat = dat >> 1;
	}
	delay(8);
}
/********��ȡ�¶�********/
uint Read_Temperature(void)									//Ӧ�ò�������1
{
	uint i,j;
	Init_DS18B20();
	Write_OneChar(0xcc);										// ����������кŵĲ���
	Write_OneChar(0x44);  	//�����¶�ת��
										
	Init_DS18B20();
	Write_OneChar(0xcc);										//����������кŵĲ���
	Write_OneChar(0xbe);										//��ȡ�¶ȼĴ����ȣ����ɶ�9���Ĵ����� ǰ���������¶�
	
	i = Read_OneChar();											//��ȡ�¶�ֵ��8λ
	j = Read_OneChar();											//��ȡ�¶�ֵ��8λ
	j = j << 8;													//��8λ����										
    i = i | j;													//�ϳ�16λ�¶�ֵ
	return(i);
}