#include <iostream>
using namespace std;
// 定义节点
struct Node {
  int data;
  Node *next;
};
// 定义头结点
Node *head = NULL;
// 插入节点
void InsertNode(int data) {
  Node *new_node = new Node;
  new_node->data = data;
  new_node->next = head;
  head = new_node;
}
// 删除节点
void DeleteNode(int data) {
  Node *pre = NULL, *cur = head;
  while (cur != NULL && cur->data != data) {
    pre = cur;
    cur = cur->next;
  }
  if (cur != NULL) {
    if (pre == NULL) {
      head = head->next;
    } else {
      pre->next = cur->next;
    }
    delete cur;
  }
}
// 查找节点
Node *FindNode(int data) {
  Node *cur = head;
  while (cur != NULL && cur->data != data) {
    cur = cur->next;
  }
  return cur;
}
// 打印链表
void PrintList() {
  Node *cur = head;
  while (cur != NULL) {
    cout << cur->data << " ";
    cur = cur->next;
  }
  cout << endl;
}
int main() {
  // 插入节点
  InsertNode(1);
  InsertNode(2);
  InsertNode(3);
  // 打印链表
  PrintList();
  // 删除节点
  DeleteNode(2);
  // 打印链表
  PrintList();
  // 查找节点
  Node *node = FindNode(3);
  if (node != NULL) {
    cout << "找到节点：" << node->data << endl;
  } else {
    cout << "未找到节点" << endl;
  }
  return 0;
}