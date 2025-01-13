#include "ds1302.h"
void ds1302_reset() {
    RST = 0; // 停止数据传送
    SCK = 0; // 时钟总线清零
    RST = 1; // 数据操作
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
    uint8 i, dat = 0; // 用dat存储读到的数据
    for (i = 0; i < 8; i++) {
        dat >>= 1;
        if (SDA == 1) dat |= 0x80; // 因为从低位开始读
        SCK = 1;
        SCK = 0;
    }
    return dat;
}
void ds1302_clear_WP() {
    ds1302_reset();
    RST = 1;
    ds1302_write_byte(0x8E); // 写入地址
    ds1302_write_byte(0x00); // 写入数据
    SDA = 0;
    RST = 0;
}

void ds1302_set_WP() {
    ds1302_reset();
    RST = 1;
    ds1302_write_byte(0x8E); // 写入地址
    ds1302_write_byte(0x80); // 写入数据
    SDA = 0;
    RST = 0;
}

void ds1302_write(uint8 addr, uint8 dat) {
    ds1302_reset();
    RST = 1;
    ds1302_write_byte(addr); // 写入地址
    ds1302_write_byte(dat); // 写入数据
    RST = 0;
    SDA = 0;
}

uint8 ds1302_read(uint8 addr) {
    uint8 temp = 0; // 存储读出来的数据
    ds1302_reset();
    RST = 1;
    ds1302_write_byte(addr); // 写入地址
    temp = ds1302_read_byte(); // 写入数据
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
    ds1302_clear_WP(); // 对ds1302操作前先将wp位清零
    temp = DS1302_W_ADDR; // 写入起始位置
    for (i = 0; i < 7; i++) {
        ds1302_write(temp, timedata[i]);
        temp += 2;
    }
    ds1302_set_WP();
}

void read_time(uint8 *timedata) {
    uint8 i, temp;
    temp = DS1302_R_ADDR; // 读起始位置
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
    d = ds1302_read(0x81); // 读秒
    sec = BCD_DEC_conv(d); // 得到秒   
    d = ds1302_read(0x83); // 读分
    min = BCD_DEC_conv(d); // 得到分
    d = ds1302_read(0x85); // 读小时
    hour = BCD_DEC_conv(d); // 得到小时
    d = ds1302_read(0x87); // 读日
    date = BCD_DEC_conv(d); // 得到日
    d = ds1302_read(0x89); // 读月
    month = BCD_DEC_conv(d); // 得到月
    d = ds1302_read(0x8b); // 读星期
    week = BCD_DEC_conv(d); // 得到星期
    d = ds1302_read(0x8d); // 读年
    year = BCD_DEC_conv(d); // 得到年
}

void time_adj(void) {
    sec = DEC_BCD_conv(sec);
    min = DEC_BCD_conv(min);    
    hour = DEC_BCD_conv(hour);  
    year = DEC_BCD_conv(year);  
    month = DEC_BCD_conv(month);    
    date = DEC_BCD_conv(date);  
    
    ds1302_clear_WP(); // 写操作，可以对DS1302调整
    ds1302_write(0x80, sec); // 写秒
    ds1302_write(0x82, min); // 写分
    ds1302_write(0x84, hour); // 写时
    ds1302_write(0x86, date); // 写日
    ds1302_write(0x88, month); // 写月 
    ds1302_write(0x8a, week); // 写星期
    ds1302_write(0x8c, year); // 写年
    ds1302_set_WP(); // 写保护
}
