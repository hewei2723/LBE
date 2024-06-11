#include <iostream>
using namespace std;
// 定义线性表的结构体
struct SeqList {
    int *data; // 存储元素的数组
    int length; // 线性表长度
    int capacity; // 数组容量
};
// 初始化线性表
void init(SeqList &list, int capacity) {
    list.data = new int[capacity];
    list.length = 0;
    list.capacity = capacity;
}
// 销毁线性表
void destroy(SeqList &list) {
    delete[] list.data;
}
// 获取元素
bool getElem(SeqList &list, int index, int &elem) {
    if (index < 0 || index >= list.length) {
        return false; // 索引越界
    }
    elem = list.data[index];
    return true;
}
// 插入元素
bool insert(SeqList &list, int index, int elem) {
    if (index < 0 || index > list.length || list.length >= list.capacity) {
        return false; // 位置无效或线性表已满
    }
    for (int i = list.length; i > index; i--) {
        list.data[i] = list.data[i - 1]; // 后移元素
    }
    list.data[index] = elem;
    list.length++;
    return true;
}
// 删除元素
bool remove(SeqList &list, int index) {
    if (index < 0 || index >= list.length) {
        return false; // 索引越界
    }
    for (int i = index; i < list.length - 1; i++) {
        list.data[i] = list.data[i + 1]; // 前移元素
    }
    list.length--;
    return true;
}

// 打印线性表
void print(SeqList &list) {
    cout << "SeqList: ";
    for (int i = 0; i < list.length; i++) {
        cout << list.data[i] << " ";
    }
    cout << endl;
}

int main() {
    SeqList list;
    init(list, 5); // 初始化线性表，设置容量为5

    insert(list, 0, 1); // 在位置0插入元素1
    insert(list, 1, 2); // 在位置1插入元素2
    insert(list, 2, 3); // 在位置2插入元素3
    insert(list, 1, 4); // 在位置1插入元素4

    print(list); // 打印线性表

    int elem;
    getElem(list, 2, elem); // 获取位置2的元素
    cout << "Element at index 2: " << elem << endl;

    remove(list, 1); // 删除位置1的元素
    print(list); // 打印线性表

    destroy(list); // 销毁线性表
    return 0;
}
