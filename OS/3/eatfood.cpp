//吃饱了的的知识分子
#include <iostream>
#include <thread>
#include <chrono>
#include <windows.h> // 需要引入这个头文件
using namespace std;
typedef struct 
{
    int value;//1表示可以使用，0表示不能使用
}semaphore;
semaphore chopsticks[5]= {1,1,1,1,1};//五根筷子是独立的五个对象
semaphore eater={4};//同时用的筷子的最多有四个
void delay(int t) {
    // 模拟延迟函数
    this_thread::sleep_for(chrono::milliseconds(t));
}
// wait操作
void wait(semaphore* s) {
    while (true) {
        if (s->value > 0) { // 模拟信号量值检查
            s->value--;
            break;
        }
        delay(10); // 模拟阻塞
    }
}
// signal操作
void signal(semaphore* s) {
    s->value++;
}
//当哲学家拿到左筷子和右筷子后，就可以吃饭了
void philosopher(int i) {
    do
    {
        wait(&eater); //等待吃饭的信号量
        wait(&chopsticks[i]);//拿起左筷子
        cout<<"哲学家"<<i<<"拿起左筷子\n";
        wait(&chopsticks[(i+1)%5]);//拿起右筷子
        cout<<"哲学家"<<i<<"拿起右筷子\n";
        cout<<"哲学家"<<i<<"在吃饭...\n";
        delay(1500);//吃饭1.5时间刻度
        signal(&chopsticks[i]);//放下左筷子
        cout<<"哲学家"<<i<<"放下左筷子\n";
        signal(&chopsticks[(i+1)%5]);//放下右筷子
        cout<<"哲学家"<<i<<"放下右筷子\n";
        signal(&eater);//吃饭结束，释放吃饭的信号量
        cout<<"哲学家"<<i<<"在思考...\n";
        delay(3000);//思考3时间刻度
    } while (true); 
}
int main() { 
    SetConsoleOutputCP(CP_UTF8);  // 设置控制台输出为 UTF-8 编码
    thread t[5];
    for (int i = 0; i < 5; i++) {
        t[i] = thread(philosopher, i);
    }
    for (int i = 0; i < 5; i++) {
        t[i].join();
    }
    return 0;
    
}