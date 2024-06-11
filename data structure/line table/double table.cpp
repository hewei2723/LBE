#include <iostream>
using namespace std;
// 定义双向链表节点结构体
struct Node {
    int data; // 节点数据
    Node* prev; // 指向前一个节点的指针
    Node* next; // 指向后一个节点的指针
};
// 在双向链表头部插入新节点
void insertAtBeginning(Node* &head, int value) {
    Node* newNode = new Node; // 创建新节点
    newNode->data = value;
    newNode->prev = nullptr;
    newNode->next = head;
    if (head != nullptr) {
        head->prev = newNode;
    }
    head = newNode;
}
// 打印双向链表中的元素（从头到尾）
void printForward(Node* head) {
    cout << "双向链表中的元素（从头到尾）: ";
    Node* current = head;
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}
// 打印双向链表中的元素（从尾到头）
void printBackward(Node* tail) {
    cout << "双向链表中的元素（从尾到头）: ";
    Node* current = tail;
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->prev;
    }
    cout << endl;
}
int main() {
    Node* head = nullptr; // 头指针初始化为空
    // 向双向链表头部插入一些元素
    insertAtBeginning(head, 3);
    insertAtBeginning(head, 2);
    insertAtBeginning(head, 1);
    // 打印双向链表中的元素（从头到尾）
    printForward(head);
    // 打印双向链表中的元素（从尾到头）
    // 为了从尾到头遍历，需要先找到链表的尾节点
    Node* current = head;
    while (current->next != nullptr) {
        current = current->next;
    }
    printBackward(current);
    return 0;
}
