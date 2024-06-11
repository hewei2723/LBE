#include <iostream>
using namespace std;

// 定义链表节点结构体
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    int cur = 0;
    // 删除链表倒数第n个节点的函数
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (!head) return NULL;
        head->next = removeNthFromEnd(head->next, n);
        cur++;
        if (n == cur) return head->next;
        return head;
    }
};
// 测试函数
void test() {
    // 创建链表：1 -> 2 -> 3 -> 4 -> 5
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    Solution solution;
    ListNode *result = solution.removeNthFromEnd(head, 2);
    // 打印删除节点后的链表
    ListNode *current = result;
    while (current) {
        cout << current->val << " ";
        current = current->next;
    }
    cout << endl;
}
int main() {
    test();
    return 0;
}
