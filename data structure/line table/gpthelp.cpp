#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* next;
};
// 插入节点到链表尾部
void insert(Node* &head, int val) {
    Node* newNode = new Node; 
    newNode->data = val;
    newNode->next = nullptr;
    if (head == nullptr) {
        head = newNode;
    } else {
        Node* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newNode;
    }
}

// 打印链表中的元素
void printList(Node* head) {
    cout << "链表中的元素: ";
    Node* current = head;
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}
int main() {
    Node* head = nullptr; 
    insert(head, 1);
    insert(head, 2);
    insert(head, 5);
    insert(head, 7);
    printList(head);
    return 0;
}
