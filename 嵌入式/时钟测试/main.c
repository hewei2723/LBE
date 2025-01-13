#include <reg52.h>
typedef unsigned char uint8;
typedef unsigned int uint16;

sbit SDA = P3^5;  // 数据
sbit SCK = P3^7;  // 时钟
sbit RST = P3^4;  // DS1302复位(片选)
sbit le = P1^0;

uint8 time[7] = {50, 41, 20, 9, 8, 4, 12}; // 秒分时日月周年
unsigned int poi[] = {0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 0x40, 0x80};
unsigned int seg[] = {0xc0, 0xf9, 0xa4, 0xb0, 0x99, 0x92, 0x82, 0xf8, 0x80, 0x90};

#define DS1302_W_ADDR 0x80
#define DS1302_R_ADDR 0x81

void ds1302_reset() {
    RST = 0; // 停止数据传送
    SCK = 0; // 时钟总线清零
    RST = 1; // 数据操作
}

// 写一个字节
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

// 清除写保护
void ds1302_clear_WP() {
    ds1302_reset();
    RST = 1;
    ds1302_write_byte(0x8E); // 写入地址
    ds1302_write_byte(0x00); // 写入数据
    SDA = 0;
    RST = 0;
}

// 设置写保护
void ds1302_set_WP() {
    ds1302_reset();
    RST = 1;
    ds1302_write_byte(0x8E); // 写入地址
    ds1302_write_byte(0x80); // 写入数据
    SDA = 0;
    RST = 0;
}

// 写入ds1302
void ds1302_write(uint8 addr, uint8 dat) {
    ds1302_reset();
    RST = 1;
    ds1302_write_byte(addr); // 写入地址
    ds1302_write_byte(dat); // 写入数据
    RST = 0;
    SDA = 0;
}

// 从ds1302读数据
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

// 设定时钟数据
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

// 读时钟数据（BCD格式）
void read_time(uint8 *timedata) {
    uint8 i, temp;
    temp = DS1302_R_ADDR; // 读起始位置
    for (i = 0; i < 7; i++) {
        timedata[i] = ds1302_read(temp);
        temp += 2;
    }
}

/* UART初始化
 * 波特率：9600
 */
void uart_init(void) {
    TMOD = 0x21;
    SCON = 0x50;
    TH1 = 0xFD;
    TL1 = 0xFD;
    TR1 = 1;
}

/* UART发送一字节 */
void UART_Send_Byte(uint8 dat) {
    SBUF = dat;
    while (TI == 0);
    TI = 0;
}

/* 将数据转换成ASC码并通过UART发送出去 */
void UART_Send_Dat(uint8 dat) {
    UART_Send_Byte(dat / 16 + '0');
    UART_Send_Byte(dat % 16 + '0');
}

void display(int p, int num) {
    P0 = 0xff;
    P0 = poi[p];
    le = 1;
    le = 0;
    P0 = seg[num];
    delay(1000);
}

void main() {
    uart_init();
    set_time(&time); // 设定时间值

    while (1) {
        read_time(&time); // 秒分时日月周年

        UART_Send_Dat(time[2]);
        display(7, time[2] / 10);
        display(6, time[2] % 10);
        UART_Send_Byte(':');
        UART_Send_Dat(time[1]);
        display(4, time[1] / 10);
        display(3, time[1] % 10);
        UART_Send_Byte(':');
        UART_Send_Dat(time[0]);
        display(1, time[0] / 10);
        display(0, time[0] % 10);
        UART_Send_Byte('\r');
        UART_Send_Byte('\n');

        delay(10000);
    }
}
