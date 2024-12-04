#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

#define N 5 // 哲学家的数量

// 哲学家的状态
#define THINKING 0
#define HUNGRY 1
#define EATING 2

sem_t mutex;                           // 保护共享资源的互斥信号量
sem_t sem[N];                          // 每个哲学家的信号量，控制是否能进餐
int state[N];                          // 哲学家当前的状态
int philosophers[N] = {0, 1, 2, 3, 4}; // 哲学家的编号

// 打印哲学家状态
void print_state(int i, const char *action)
{
    printf("Philosopher %d is %s\n", i + 1, action);
}

// 检查哲学家是否可以进餐
void check(int i)
{
    if (state[i] == HUNGRY && state[(i + N - 1) % N] != EATING && state[(i + 1) % N] != EATING)
    {
        // 哲学家可以进餐
        state[i] = EATING;
        print_state(i, "eating");

        // 允许哲学家进餐
        sem_post(&sem[i]);
    }
}

// 哲学家拿起筷子
void take_forks(int i)
{
    sem_wait(&mutex);  // 进入临界区
    state[i] = HUNGRY; // 哲学家想要进餐
    print_state(i, "hungry");
    check(i);          // 检查左边和右边的哲学家是否在进餐
    sem_post(&mutex);  // 退出临界区
    sem_wait(&sem[i]); // 等待筷子可用
}

// 哲学家放下筷子
void put_forks(int i)
{
    sem_wait(&mutex);    // 进入临界区
    state[i] = THINKING; // 哲学家思考
    print_state(i, "thinking");

    // 检查左边和右边的哲学家是否可以进餐
    check((i + N - 1) % N);
    check((i + 1) % N);
    sem_post(&mutex); // 退出临界区
}
// 哲学家线程执行函数
void *philosopher(void *num)
{
    int i = *((int *)num);
    while (1)
    {
        print_state(i, "thinking");
        sleep(1); // 哲学家思考一段时间

        take_forks(i); // 哲学家拿起筷子
        sleep(1);      // 哲学家进餐一段时间
        put_forks(i);  // 哲学家放下筷子
    }
}

int main()
{
    int i;
    pthread_t tid[N];

    // 初始化信号量
    sem_init(&mutex, 0, 1); // 互斥信号量初始值为1
    for (i = 0; i < N; i++)
    {
        sem_init(&sem[i], 0, 0); // 每个哲学家的信号量初始值为0
    }

    // 创建哲学家线程
    for (i = 0; i < N; i++)
    {
        pthread_create(&tid[i], NULL, philosopher, &philosophers[i]);
    }

    // 等待所有哲学家线程结束（实际上是无限循环）
    for (i = 0; i < N; i++)
    {
        pthread_join(tid[i], NULL);
    }

    // 销毁信号量
    sem_destroy(&mutex);
    for (i = 0; i < N; i++)
    {
        sem_destroy(&sem[i]);
    }

    return 0;
}