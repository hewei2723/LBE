void start_2404(void)
{
	sda = 1;
	nop;
	scl = 1;
	nop;
	sda = 0;
	nop;
	scl = 0;
	nop;
}

void stop_2404(void)
{
	sda = 0;
	nop;
	scl = 1;
	nop;
	sda = 1;
	nop;
}

void ack_2404(void)
{
	uchar i = 255;
	scl = 1;
	nop;
	while(sda && i--);
	scl = 0;
	nop;
}

void init_2404(void)
{
	sda = 1; nop;	   					//³£Ì¬
	scl = 1; nop;	   					//³£Ì¬
}

uchar read_onebyte_2404(void)
{
	uchar i, dat;
	sda = 1; 							
	for(i = 8; i > 0; i--)
	{
		scl = 1;
		dat <<= 1;
		if(sda) dat |= 0x01;
		scl = 0;
	}
	sda = 1; scl = 0;
	return(dat);
}

void write_onebyte_2404(uchar dat)
{
	uchar i;
	for(i = 8; i > 0; i--)
	{
		sda = (bit)(dat & 0x80);		
		dat <<= 1;
		scl = 1;
		scl = 0;
	}
	sda = 1; scl = 0;
}

void write_add_dat_2404(uchar add, uchar dat)
{
	start_2404();
	write_onebyte_2404(0xa0);
	ack_2404();
	write_onebyte_2404(add);
	ack_2404();
	write_onebyte_2404(dat);
	ack_2404();
	stop_2404();
}
uchar read_add_dat_2404(uchar add)
{
	uchar dat;
	start_2404();
	write_onebyte_2404(0xa0);
	ack_2404();
	write_onebyte_2404(add);
	ack_2404();
	start_2404();
	write_onebyte_2404(0xa1);
	ack_2404();
	dat = read_onebyte_2404();
	stop_2404();
	return(dat);
}