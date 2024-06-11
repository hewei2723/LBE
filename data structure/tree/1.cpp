#include <iostream>
#include <queue>
using namespace std;

// 二叉树节点结构
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {} // 构造函数，初始化节点值和左右子节点为空
};
// 创建三层完全二叉树
TreeNode* createCompleteBinaryTree() {
    TreeNode* root = new TreeNode(1); // 创建根节点
    root->left = new TreeNode(2); // 创建第二层左子节点
    root->right = new TreeNode(3); // 创建第二层右子节点
    root->left->left = new TreeNode(4); // 创建第三层左子节点
    root->left->right = new TreeNode(5); // 创建第三层右子节点
    root->right->left = new TreeNode(6); // 创建第三层左子节点
    root->right->right = new TreeNode(7); // 创建第三层右子节点
    return root;
}
// 层序遍历二叉树
void levelOrderTraversal(TreeNode* root) {
    if (root == nullptr) return; // 如果根节点为空，则直接返回
    queue<TreeNode*> q; // 创建一个队列来存放节点
    q.push(root); // 将根节点加入队列
    while (!q.empty()) { // 当队列不为空时循环
        int size = q.size(); // 获取当前队列的大小
        for (int i = 0; i < size; ++i) { // 遍历当前层的所有节点
            TreeNode* curr = q.front(); // 获取队列头部节点
            q.pop(); // 弹出队列头部节点
            cout << curr->val << " "; // 打印当前节点的值
            if (curr->left) q.push(curr->left); // 如果当前节点有左子节点，则将左子节点加入队列
            if (curr->right) q.push(curr->right); // 如果当前节点有右子节点，则将右子节点加入队列
        }
        cout << endl; // 打印换行
    }
}
int main() {
    TreeNode* root = createCompleteBinaryTree(); // 创建三层完全二叉树
    cout << "完全二叉树：" << endl;
    levelOrderTraversal(root); // 层序遍历二叉树
    return 0;
}