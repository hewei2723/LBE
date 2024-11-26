#include <iostream>
#include <thread> // 多线程库
using namespace std;

int buffer[5];  // 缓冲池
int in = 0;     // 生产者插入位置
int out = 0;    // 消费者取出位置

typedef struct {
    int value;   // 信号量值
    int process; // 1表示进程放行，0表示阻塞
} semaphore;
void delay(int x) {
    while (x--);
    
}
// 初始化信号量
semaphore mutex = {1, 1};  // 互斥信号量
semaphore full = {0, 0};   // 满缓冲区信号量
semaphore Nempty = {5, 1}; // 空缓冲区信号量

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
// 生产者线程函数
void producer() {
    for (int i = 0; i < 10; i++) { // 假设生产10个产品
        wait(&Nempty);  // 判断是否有空缓冲区
        wait(&mutex);   // 获取互斥信号量
        // 生产食物
        buffer[in] = i; // 放入缓冲区
        cout << "生产者放入: " << buffer[in] << " 在 " << in << "号槽位" << endl;
        in = (in + 1) % 5; // 更新生产者插入位置
        signal(&mutex);    // 释放互斥信号量
        signal(&full);     // 更新满缓冲区信号量
        delay(1000); // 模拟生产延迟
    }
}

// 消费者线程函数
void consumer() {
    for (int i = 0; i < 10; i++) { // 假设消费10个产品
        wait(&full);    // 判断是否有满缓冲区
        wait(&mutex);   // 获取互斥信号量
        // 消费食物
        int item = buffer[out]; // 从缓冲区取出食物
        cout << "消费者取出: " << item << " 在 " << out << "号槽位" << endl;
        out = (out + 1) % 5; // 更新消费者取出位置
        signal(&mutex);      // 释放互斥信号量
        signal(&Nempty);     // 更新空缓冲区信号量
        delay(15500); // 模拟消费延迟
    }
}

int main() {
    // 创建生产者和消费者线程
    thread producerThread(producer);
    thread consumerThread(consumer);
    // 等待线程执行完毕
    producerThread.join();
    consumerThread.join();
    return 0;
}
