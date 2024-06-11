#include <iostream>
using namespace std;
struct lb
{
    int data;
    lb *node;
    /* data */
};
void in(lb* &head, int num) {
    lb* lb1 = new lb;
    lb1->data = num;
    lb1->node = head;
    head = lb1;
}
void printList(lb* head) {
    cout << "链表中的元素: ";
    lb* current = head;
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->node;
    }
    cout << endl;
}
int main(){
    lb* head=nullptr;
    in(head,1);
    in(head,2);
    in(head,3);
    printList(head);
    head=nullptr;
    printList(head);
    return 0;
}