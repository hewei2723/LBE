#include <stdio.h>
#include <stdlib.h>

// 定义二叉树节点结构
struct btnode {
    char data;
    int lbit;
    int rbit;
    struct btnode *lchild;
    struct btnode *rchild;
};

typedef struct btnode NODE;
NODE *pre = NULL;

// 函数声明
NODE* create();
void inthread(NODE* root);
void inthreading(NODE* p);
void invodth(NODE* h);

// 主函数
int main() {
    NODE *root;

    printf("\nAt first, we create a tree!\n");
    printf("Please input the data of the tree (use space for null node):\n");

    root = create();
    inthread(root);

    return 0;
}

// 创建二叉树
NODE* create() {
    char ch;
    if (scanf(" %c", &ch) != 1) { // 读取字符，忽略前导空白字符
        printf("Failed to read character\n");
        return NULL;
    }
    if (ch == ' ')
        return NULL;

    NODE *p = (NODE *)malloc(sizeof(NODE));
    if (p == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    p->data = ch;
    p->lbit = 0;
    p->rbit = 0;
    p->lchild = create();
    p->rchild = create();
    return p;
}

// 中序线索化二叉树
void inthread(NODE *root) {
    NODE *t = (NODE *)malloc(sizeof(NODE));
    if (t == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    t->lbit = 0;
    t->rbit = 1;
    t->rchild = t;
    if (root == NULL) {
        t->lchild = t;
    } else {
        pre = t;
        inthreading(root);
        t->lchild = root;
        pre->rchild = t;
        pre->rbit = 1;
        t->rchild = pre;
    }
    printf("\nInorder traversal of threaded binary tree:\n");
    invodth(t);
}

// 中序线索化过程
void inthreading(NODE *p) {
    if (p != NULL) {
        inthreading(p->lchild);
        if (p->lchild == NULL) {
            p->lbit = 1;
            p->lchild = pre;
        }
        if (pre != NULL && pre->rchild == NULL) {
            pre->rbit = 1;
            pre->rchild = p;
        }
        pre = p;
        inthreading(p->rchild);
    }
}

// 中序遍历线索化二叉树
void invodth(NODE *h) {
    NODE *p = h->lchild;
    while (p != h) {
        while (p->lbit == 0)
            p = p->lchild;
        printf(" %c", p->data);
        while (p->rbit == 1 && p->rchild != h) {
            p = p->rchild;
            printf(" %c", p->data);
        }
        p = p->rchild;
    }
    printf("\n");
}