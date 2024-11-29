#include <iostream>
#include <thread>
#include <chrono>
#include <mutex>
#include <string>
#include <vector>
#include <iomanip> // for setw
#include <windows.h> // 需要引入这个头文件

using namespace std;

typedef struct {
    int value; // 信号量值
} semaphore;

semaphore chopsticks[5] = {1, 1, 1, 1, 1}; // 五根筷子
semaphore eater = {4};                     // 最多允许4个哲学家同时就餐
mutex mtx;                                 // 控制台输出保护

vector<string> philosopherStates(5, "思考中🆘"); // 哲学家状态

void delay(int t) {
    this_thread::sleep_for(chrono::milliseconds(t));
}

// wait操作
void wait(semaphore *s) {
    while (true) {
        if (s->value > 0) {
            s->value--;
            break;
        }
        delay(10); // 模拟阻塞
    }
}

// signal操作
void signal(semaphore *s) {
    s->value++;
}

// 动态显示状态
void displayStates() {
    lock_guard<mutex> lock(mtx);
    system("cls"); // Windows 使用 system("cls")
    cout << "哲学家状态:" << endl;
    for (int i = 0; i < 5; i++) {
        cout << "哲学家" << i+1 << ": " << setw(10) << philosopherStates[i]<< endl;
    }
    cout << "--------------------------" << endl;
}

// 哲学家行为
void philosopher(int i) {
    do {
        philosopherStates[i] = "等待中";
        displayStates();
        wait(&eater); // 等待允许就餐信号量
        wait(&chopsticks[i]); // 拿起左筷子
        philosopherStates[i] = "拿左筷👀";
        displayStates();
        wait(&chopsticks[(i + 1) % 5]); // 拿起右筷子
        philosopherStates[(i + 1) % 5] = "拿右筷👀";
        displayStates();
        philosopherStates[i] = "吃饭中🤣";
        displayStates();
        delay(1500); // 模拟吃饭时间
        signal(&chopsticks[i]); // 放下左筷子
        signal(&chopsticks[(i + 1) % 5]); // 放下右筷子
        signal(&eater); // 释放就餐信号量
        philosopherStates[i] = "思考中";
        displayStates();
        delay(3000); // 模拟思考时间
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
