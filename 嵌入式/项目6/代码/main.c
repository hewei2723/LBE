#include <reg51.h>

int seg[10] = {0xc0, 0xf9, 0xa4, 0xb0, 0x99, 0x92, 0x82, 0xf8, 0x80, 0x90};
int ptwo[8] = {0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 0x40, 0x80};
int i = 0, hours, minutes, second, cp, a, b;

void delay(int x)
{
    while (x--)
        ;
}

void timer0_init(void)
{
    TMOD = 0x01; // 设置定时器T0为模式1
    TL0 = (65535 - 2000) % 256;
    TH0 = (65535 - 2000) / 256;
    EA = 1;  // 全局中断使能
    ET0 = 1; // 定时器0中断使能
    TR0 = 1; // 启动T0定时器
}
void display_digit(int position, int value)
{
    P0 = seg[value];
    P2 = ptwo[position];
    delay(100);
    P0 = 0xFF; 
		P0 = 0xBF;
    P2 = 0x24;// 清除显示
}

void display_time(int i)
{
    // 计算当前小时、分钟和秒
    hours = i / 3600;
    minutes = (i % 3600) / 60;
    second = i % 60;

    // 显示秒
    display_digit(7, second % 10);  // 显示秒的个位
    display_digit(6, second / 10);  // 显示秒的十位

    // 显示分钟
    display_digit(4, minutes % 10); // 显示分钟的个位
    display_digit(3, minutes / 10); // 显示分钟的十位

    // 显示小时
    display_digit(1, hours % 10);   // 显示小时的个位
    display_digit(0, hours / 10);   // 显示小时的十位
}


int showStu()
{
    int stu[8] = {2, 2, 0, 1, 0, 6, 1, 1};
    int i;
    for (i = 0; i < 8; i++)
    {
        P0 = seg[stu[i]];
        P2 = ptwo[i];
        delay(150);
        P0 = 0Xff;
    }
    return 0;
}
void timer0_isr(void) interrupt 1
{
    TL0 = 0x78; // 重装计数值
    TH0 = 0xec;
    cp++;

    if (cp >= 200)
    { // 定时到达后递增秒数
        cp = 0;
        i++;
        if (i >= 60 * 60 * 24)
        { // 防止溢出，一天重置为0
            i = 0;
        }
    }
    if (i > 1)
    {
        display_time(i);
    }
    else
    {
        showStu();
    }
}

void main()
{
    // 初始化显示
    timer0_init(); // 启动定时器
    while (1)
        ;
}
