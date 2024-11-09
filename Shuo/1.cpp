#include <iostream>

struct Node {
    int data;       // 节点的数据部分
    Node* next;     // 指向下一个节点的指针
};

int main() {
    // 创建第一个节点并设为头节点
    Node* head = new Node;  // 分配第一个节点的内存并设为头节点
    head->data = 1;         // 给第一个节点赋值
    head->next = nullptr;   // 初始化指向下一个节点的指针为空

    // 用一个指针变量node来操作链表
    Node* node = head;

    // 创建第二个节点
    node->next = new Node;  // 分配第二个节点的内存并将第一个节点的next指向它
    node = node->next;      // 将node指向新创建的节点
    node->data = 2;         // 给第二个节点赋值
    node->next = nullptr;   // 初始化指向下一个节点的指针为空

    // 创建第三个节点
    node->next = new Node;  // 分配第三个节点的内存并将第二个节点的next指向它
    node = node->next;      // 将node指向新创建的节点
    node->data = 3;         // 给第三个节点赋值
    node->next = nullptr;   // 初始化指向下一个节点的指针为空

    // 打印链表的节点值
    node = head;  // 重置node指向链表的头节点
    while (node != nullptr) {
        std::cout << node->data << " -> ";
        node = node->next;
    }
    std::cout << "nullptr" << std::endl;

    // 释放链表的内存
    node = head;
    while (node != nullptr) {
        Node* temp = node;
        node = node->next;
        delete temp;
    }

    return 0;
}
