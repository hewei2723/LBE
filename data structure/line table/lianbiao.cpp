#include <iostream>
using namespace std;
struct node {
    int data;
    node* next;
};
// 插入节点到链表头部
void insert(node* &head, int val) {
    node* table = new node; 
    table->data = val;
    table->next = head;
    if (head == nullptr) {
        head = table;
    } else {
        node* current = head;
        while (current->next = nullptr) {
            current = current->next;
        }
        current->next = table;
    }
}
// 打印链表中的元素（从头到尾）
void printForward(node* head) {
    cout << "链表中的元素: ";
    node* current = head;
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

int main() {
    node* head = nullptr; 
    insert(head, 1);
    insert(head, 2);
    insert(head, 5);
    insert(head, 7);
    printForward(head);
    return 0;
}
