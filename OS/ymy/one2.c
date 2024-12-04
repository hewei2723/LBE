#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

#define BUFFER_SIZE 10

int buffer[BUFFER_SIZE];
int count = 0;
sem_t empty;
sem_t full;

void *producer(void *arg) {
    int i;
    for (i = 0; i < 20; i++) {
        sem_wait(&empty); // 等待缓冲区有空位
        buffer[count] = i;
        count++;
        sem_post(&full); // 通知消费者缓冲区有数据
    }
    pthread_exit(NULL);
}

void *consumer(void *arg) {
    int i;
    for (i = 0; i < 20; i++) {
        sem_wait(&full); // 等待缓冲区有数据
        count--;
        sem_post(&empty); // 通知生产者缓冲区有空位
    }
    pthread_exit(NULL);
}

int main() {
    pthread_t producer_thread, consumer_thread;

    sem_init(&empty, 0, BUFFER_SIZE); // 初始化空信号量，初始值为缓冲区大小
    sem_init(&full, 0, 0); // 初始化满信号量，初始值为0

    pthread_create(&producer_thread, NULL, producer, NULL);
    pthread_create(&consumer_thread, NULL, consumer, NULL);

    pthread_join(producer_thread, NULL);
    pthread_join(consumer_thread, NULL);

    sem_destroy(&empty);
    sem_destroy(&full);

    return 0;
}

//在这个示例代码中，我们定义了一个缓冲区`buffer`和一个计数器`count`，用于记录缓冲区中的数据数量。我们还定义了两个信号量`empty`和`full`，分别用于控制缓冲区有空位和有数据。

//生产者线程通过`sem_wait(&empty)`等待缓冲区有空位，然后将数据放入缓冲区，并通过`sem_post(&full)`通知消费者线程缓冲区有数据。消费者线程通过`sem_wait(&full)`等待缓冲区有数据，然后从缓冲区中取出数据，并通过`sem_post(&empty)`通知生产者线程缓冲区有空位。

//最后，我们在`main`函数中创建生产者线程和消费者线程，并等待它们执行完毕。在程序结束时，我们销毁信号量。

//请注意，这只是一个简单的示例代码，实际的生产者消费者问题可能需要更复杂的逻辑和同步机制。