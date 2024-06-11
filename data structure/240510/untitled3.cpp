#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int DataType; // 修改为整数类型
typedef struct node {
    DataType data;
    struct node *next;
} ListNode;
typedef ListNode *LinkList;

LinkList CreateListR1(void);
void PrintList(LinkList head);
ListNode *GetNode(LinkList head, int i);
void InsertList(LinkList head, DataType x, int i);
void DeleteList(LinkList head, int i);

int main() {
    LinkList head;
    DataType x;
    int i;
    
    head = CreateListR1();
    PrintList(head);
    
    printf("请输入欲插入的元素：");
    scanf("%d", &x);
    printf("请输入欲插入元素的位置：");
    scanf("%d", &i);
    InsertList(head, x, i);
    PrintList(head);
    
    printf("请输入欲删除结点的位置：");
    scanf("%d", &i);
    DeleteList(head, i);
    PrintList(head);
    
    return 0;
}

LinkList CreateListR1(void) {
    LinkList head = (ListNode *)malloc(sizeof(ListNode));
    head->next = NULL;
    ListNode *s, *r;
    char input[100];  // 假设一行最多100个字符
    char *token;
    
    // 清除输入缓存
    int c;
    while ((c = getchar()) != '\n' && c != EOF);

    printf("请输入链表元素，以空格分隔，以回车结束：\n");
    fgets(input, sizeof(input), stdin);
    token = strtok(input, " \n");

    r = head;
    while (token != NULL) {
        s = (ListNode *)malloc(sizeof(ListNode));
        s->data = atoi(token);
        r->next = s;
        r = s;
        token = strtok(NULL, " \n");
    }
    r->next = NULL;
    return head;
}

void PrintList(LinkList head) {
    ListNode *p = head->next;
    while (p != NULL) {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

ListNode *GetNode(LinkList head, int i) {
    int j;
    ListNode *p = head->next;
    j = 1;
    while (p && j < i) {
        p = p->next;
        j++;
    }
    return p;
}

void InsertList(LinkList head, DataType x, int i) {
    ListNode *p, *s;
    p = GetNode(head, i - 1);
    if (p == NULL) {
        printf("插入位置非法\n");
        return;
    }
    s = (ListNode *)malloc(sizeof(ListNode));
    s->data = x;
    s->next = p->next;
    p->next = s;
}

void DeleteList(LinkList head, int i) {
    ListNode *p, *q;
    p = GetNode(head, i - 1);
    if (p == NULL || p->next == NULL) {
        printf("删除位置非法\n");
        return;
    }
    q = p->next;
    p->next = q->next;
    free(q);
}
