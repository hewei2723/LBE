#include <reg52.h>
typedef unsigned char uint8;
typedef unsigned int uint16;

sbit SDA = P3^5;  // ����
sbit SCK = P3^7;  // ʱ��
sbit RST = P3^4;  // DS1302��λ(Ƭѡ)
sbit le = P1^0;

uint8 time[7] = {50, 41, 20, 9, 8, 4, 12}; // ���ʱ��������
unsigned int poi[] = {0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 0x40, 0x80};
unsigned int seg[] = {0xc0, 0xf9, 0xa4, 0xb0, 0x99, 0x92, 0x82, 0xf8, 0x80, 0x90};

#define DS1302_W_ADDR 0x80
#define DS1302_R_ADDR 0x81

void ds1302_reset() {
    RST = 0; // ֹͣ���ݴ���
    SCK = 0; // ʱ����������
    RST = 1; // ���ݲ���
}

// дһ���ֽ�
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

// ���д����
void ds1302_clear_WP() {
    ds1302_reset();
    RST = 1;
    ds1302_write_byte(0x8E); // д���ַ
    ds1302_write_byte(0x00); // д������
    SDA = 0;
    RST = 0;
}

// ����д����
void ds1302_set_WP() {
    ds1302_reset();
    RST = 1;
    ds1302_write_byte(0x8E); // д���ַ
    ds1302_write_byte(0x80); // д������
    SDA = 0;
    RST = 0;
}

// д��ds1302
void ds1302_write(uint8 addr, uint8 dat) {
    ds1302_reset();
    RST = 1;
    ds1302_write_byte(addr); // д���ַ
    ds1302_write_byte(dat); // д������
    RST = 0;
    SDA = 0;
}

// ��ds1302������
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

// �趨ʱ������
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

// ��ʱ�����ݣ�BCD��ʽ��
void read_time(uint8 *timedata) {
    uint8 i, temp;
    temp = DS1302_R_ADDR; // ����ʼλ��
    for (i = 0; i < 7; i++) {
        timedata[i] = ds1302_read(temp);
        temp += 2;
    }
}

/* UART��ʼ��
 * �����ʣ�9600
 */
void uart_init(void) {
    TMOD = 0x21;
    SCON = 0x50;
    TH1 = 0xFD;
    TL1 = 0xFD;
    TR1 = 1;
}

/* UART����һ�ֽ� */
void UART_Send_Byte(uint8 dat) {
    SBUF = dat;
    while (TI == 0);
    TI = 0;
}

/* ������ת����ASC�벢ͨ��UART���ͳ�ȥ */
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
    set_time(&time); // �趨ʱ��ֵ

    while (1) {
        read_time(&time); // ���ʱ��������

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
