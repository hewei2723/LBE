#include <stdio.h>
#include <stdlib.h>

typedef struct btnode {
    char data; // 数据元素
    struct btnode *lchild, *rchild; // 指向左、右孩子的指针
} NODE;

// 创建二叉树的函数
NODE* create() {
    char ch;
    scanf(" %c", &ch); // 读取一个字符并忽略前导空白字符
    if (ch == '#') {
        return NULL;
    } else {
        NODE *p = (NODE*)malloc(sizeof(NODE));
        p->data = ch;
        p->lchild = create(); // 创建左子树
        p->rchild = create(); // 创建右子树
        return p;
    }
}

// 前序遍历
void preorder(NODE *root) {
    if (root != NULL) {
        printf("%c ", root->data);
        preorder(root->lchild);
        preorder(root->rchild);
    }
}

// 中序遍历
void inorder(NODE *root) {
    if (root != NULL) {
        inorder(root->lchild);
        printf("%c ", root->data);
        inorder(root->rchild);
    }
}

// 后序遍历
void postorder(NODE *root) {
    if (root != NULL) {
        postorder(root->lchild);
        postorder(root->rchild);
        printf("%c ", root->data);
    }
}

int main() {
    NODE *root = NULL;
    int t;

    printf("首先，我们创建一棵树\n");
    printf("请输入树的节点数据（用#表示空节点）：\n");
    root = create();
    
    if (root == NULL) {
        printf("这是一棵空树！\n");
    } else {
        printf("\n1. 前序遍历\n");
        printf("2. 中序遍历\n");
        printf("3. 后序遍历\n");
        printf("请选择一种遍历方式：\n");
        scanf("%d", &t);
        switch (t) {
            case 1:
                printf("前序遍历结果：\n");
                preorder(root);
                break;
            case 2:
                printf("中序遍历结果：\n");
                inorder(root);
                break;
            case 3:
                printf("后序遍历结果：\n");
                postorder(root);
                break;
            default:
                printf("输入错误！\n");
        }
        printf("\n");
    }
    
    return 0;
}
