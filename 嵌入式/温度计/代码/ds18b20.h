
unsigned int temp_dat;
sbit dq = P1^1;
void delay(unsigned int x) { while(x--); }
void ds18b20_init(void) {
    unsigned char i = 255;
    dq = 1;
    dq = 0;
    delay(80);  
    dq = 1;
    while(dq & i--);  
    delay(20);
}

void write_ds18b20(unsigned char x) {
    unsigned char i;
    for(i = 0; i < 8; i++) {
        dq = 0;
        dq = (bit)(x & 0x01);
        delay(10);
				dq = 1;
        x = x >> 1; 
    }
    delay(8);
}

unsigned char read_ds18b20(void) {
    unsigned char i, j;
    for(i = 0; i < 8; i++) {
				dq = 0;
        dq = 0; 
				j = j >> 1;			
        dq = 1;
        if(dq) j = j | 0x80; 
        delay(10);
    }
    return(j);
}
void read_temp_ds18b20(void) {
    unsigned int i, j;
    ds18b20_init();
    write_ds18b20(0xcc);  
    write_ds18b20(0x44);  
    ds18b20_init();
    write_ds18b20(0xcc);  
    write_ds18b20(0xbe); 
    i = read_ds18b20();
    j = read_ds18b20();
    j = j << 8;
    temp_dat = i | j;
}
