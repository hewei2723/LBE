#include <iostream>
#include <thread>
using namespace std;
// 定义一个缓冲区
int buffer[5];
// 定义一个生产者一个消费者
typedef struct{
    int value;//信号量值
    int door;//是否允许对空闲缓冲区进行操作 0表示不允许 1表示允许
}semphore;
semphore mutex = {0,1};
semphore full = {0,0};//能用的盘子数量为0 所以给盘子锁住0
semphore Nempty = {5,1};//能用的盘子数量为5 所以给盘子打开1
void delay(int t){
    this_thread::sleep_for(chrono::milliseconds(t));
}
void wait(semphore *s)
{
    s->value--;
    if (s->value < 0){
        s->door = 0;//关闭大门
    }
}
void signal(semphore *s)
{
    s->value++;
    if (s->value <= 0){
        s->door = 1;//打开大门
    }
}
void producer()
{
    for (int i = 0; i < 5; i++)
    {
    
    wait(&Nempty);
    wait(&mutex);
    // 生产者生产一个产品
    buffer[i] = 1;
    cout<<"生产者往第"<<i<<"个盘子放了一个苹果"<<endl;
    signal(&Nempty);
    signal(&full);//原来的盘子是空的，现在生产了一个，所以盘子数量加1
    signal(&mutex);// 释放互斥信号量
    delay(1000);
    }
}
void consumer()
{
    for (int i = 0; i < 5; i++)
    {
    wait(&full);
    wait(&mutex);
    // 消费者消费一个产品
    cout<<"消费者从第"<<i<<"个盘子拿了一个苹果"<<endl;
    buffer[i] = 0;
    signal(&Nempty);
    signal(&mutex);      // 释放互斥信号量
    delay(2000);
    }
}

// 在生产者使用缓冲区时消费者不能对缓冲区进行操作，消费者使用缓冲区时生产者不能对缓冲区进行操作
// 设置互斥信号量保证进程互斥
int main()
{
    thread producerThread(producer);
    thread consumerThread(consumer);
    // 等待线程执行完毕
    producerThread.join();
    consumerThread.join();
}
//value是船的数量，door是入口的大门状态，0表示关门，1表示开门
//假设当前有三艘船，且船的入口大门是开着的，排队的有4个人
//进来一个人 value-1，如果value<0，则表示三艘船已经坐满了，但是有一个人在排队，意思是value=-1则door=0，表示大门关闭。
//出来一个人 value+1，也就是，结果从vlaue=-1变成了value=0，则door=1，大门打开。
//如果是两艘船4个人
//进来一个人甲 wait操作{船数value-1=2-1=1  1>0，s->value 不< 0 则door=1，大门打开。} value=1 door=1
//进来一个人乙 wait{船数value-1=1-1=0  0<0，s->value 不< 0 则door=1，大门打开。} valua=0 door=1
//进来一个人丙 wait{船数value-1=0-1=-1 -1<0，s->value < 0   则door=0，大门关闭。}value=-1 door=0
//进来一个人丁 wait{船数value-1=-1-1=-2 -2<0，s->value < 0   则door=0，大门关闭。}value=-2 door=0
//出来一个人甲 sign操作{船数value+1=-2+1=-1  -1<=0，s->value <= 0 则door=1，大门打开.}value=-1 door=1
