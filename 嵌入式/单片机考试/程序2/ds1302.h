// ds1302.h
#ifndef _DS1302_H_
#define _DS1302_H_

typedef unsigned char uint8;
typedef unsigned int uint16;

sbit SDA = P3^5;  // 数据
sbit SCK = P3^7;  // 时钟
sbit RST = P3^4;  // DS1302复位(片选)

#define DS1302_W_ADDR 0x80
#define DS1302_R_ADDR 0x81
void ds1302_reset();
void ds1302_write_byte(uint8 dat);
uint8 ds1302_read_byte();
void ds1302_clear_WP();
void ds1302_set_WP();
void ds1302_write(uint8 addr, uint8 dat);
uint8 ds1302_read(uint8 addr);
void delay(uint16 n);
void set_time(uint8 *timedata);
void read_time(uint8 *timedata);
void get_ds1302_time();
unsigned char BCD_DEC_conv(unsigned char x);
unsigned char DEC_BCD_conv(unsigned char x);
void time_adj();
#endif // _DS1302_H_
