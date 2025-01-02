#include "ds1302.h"
void ds1302_reset() {
    RST = 0; // ֹͣ���ݴ���
    SCK = 0; // ʱ����������
    RST = 1; // ���ݲ���
}

void ds1302_write_byte(uint8 dat) {
    uint8 i;
    for (i = 0; i < 8; i++) {
        SDA = dat & 0x01;
        SCK = 1;
        SCK = 0;
        dat >>= 1;
    }
}
uint8 ds1302_read_byte() {
    uint8 i, dat = 0; // ��dat�洢����������
    for (i = 0; i < 8; i++) {
        dat >>= 1;
        if (SDA == 1) dat |= 0x80; // ��Ϊ�ӵ�λ��ʼ��
        SCK = 1;
        SCK = 0;
    }
    return dat;
}
void ds1302_clear_WP() {
    ds1302_reset();
    RST = 1;
    ds1302_write_byte(0x8E); // д���ַ
    ds1302_write_byte(0x00); // д������
    SDA = 0;
    RST = 0;
}

void ds1302_set_WP() {
    ds1302_reset();
    RST = 1;
    ds1302_write_byte(0x8E); // д���ַ
    ds1302_write_byte(0x80); // д������
    SDA = 0;
    RST = 0;
}

void ds1302_write(uint8 addr, uint8 dat) {
    ds1302_reset();
    RST = 1;
    ds1302_write_byte(addr); // д���ַ
    ds1302_write_byte(dat); // д������
    RST = 0;
    SDA = 0;
}

uint8 ds1302_read(uint8 addr) {
    uint8 temp = 0; // �洢������������
    ds1302_reset();
    RST = 1;
    ds1302_write_byte(addr); // д���ַ
    temp = ds1302_read_byte(); // д������
    RST = 0;
    SDA = 0;
    return temp;
}

void delay(uint16 n) {
    while (n--);
}

void set_time(uint8 *timedata) {
    uint8 i;
    uint8 temp = 0;
    for (i = 0; i < 7; i++) {
        temp = timedata[i] / 10;
        timedata[i] = timedata[i] % 10;
        timedata[i] = timedata[i] + temp * 16;
    }
    ds1302_clear_WP(); // ��ds1302����ǰ�Ƚ�wpλ����
    temp = DS1302_W_ADDR; // д����ʼλ��
    for (i = 0; i < 7; i++) {
        ds1302_write(temp, timedata[i]);
        temp += 2;
    }
    ds1302_set_WP();
}

void read_time(uint8 *timedata) {
    uint8 i, temp;
    temp = DS1302_R_ADDR; // ����ʼλ��
    for (i = 0; i < 7; i++) {
        timedata[i] = ds1302_read(temp);
        temp += 2;
    }
}

unsigned char BCD_DEC_conv(unsigned char x) {
    unsigned char dec;
    dec =  0x0f & x;
    x = x >> 4;
    dec = dec + x * 10;
    return dec;
}

unsigned char DEC_BCD_conv(unsigned char x) {
    unsigned char bcd;
    bcd =  x % 10;
    x = x / 10;
    x = x << 4;
    bcd = bcd | x;
    return bcd;
}

void get_ds1302_time(void) {
    unsigned char d;
    d = ds1302_read(0x81); // ����
    sec = BCD_DEC_conv(d); // �õ���   
    d = ds1302_read(0x83); // ����
    min = BCD_DEC_conv(d); // �õ���
    d = ds1302_read(0x85); // ��Сʱ
    hour = BCD_DEC_conv(d); // �õ�Сʱ
    d = ds1302_read(0x87); // ����
    date = BCD_DEC_conv(d); // �õ���
    d = ds1302_read(0x89); // ����
    month = BCD_DEC_conv(d); // �õ���
    d = ds1302_read(0x8b); // ������
    week = BCD_DEC_conv(d); // �õ�����
    d = ds1302_read(0x8d); // ����
    year = BCD_DEC_conv(d); // �õ���
}

void time_adj(void) {
    sec = DEC_BCD_conv(sec);
    min = DEC_BCD_conv(min);    
    hour = DEC_BCD_conv(hour);  
    year = DEC_BCD_conv(year);  
    month = DEC_BCD_conv(month);    
    date = DEC_BCD_conv(date);  
    
    ds1302_clear_WP(); // д���������Զ�DS1302����
    ds1302_write(0x80, sec); // д��
    ds1302_write(0x82, min); // д��
    ds1302_write(0x84, hour); // дʱ
    ds1302_write(0x86, date); // д��
    ds1302_write(0x88, month); // д�� 
    ds1302_write(0x8a, week); // д����
    ds1302_write(0x8c, year); // д��
    ds1302_set_WP(); // д����
}
