#include "common.h"
void sumNumbers(TreeNode* root, int& sum, int num) {
    if (root) {
        num = num * 10 + root->val;
        if (!root->left && !root->right)
            sum += num;
        else {
            if (root->left) sumNumbers(root->left, sum, num);
            if (root->right) sumNumbers(root->right, sum, num);
        }
    }
}

int sumNumbers(TreeNode* root) {
    int sum = 0;
    int num = 0;
    sumNumbers(root, sum, num);
    return sum;
}

int main() {
    TreeNode* node = new TreeNode(4);
    node->left = new TreeNode(9);
    node->right = new TreeNode(0);
    node->left->left = new TreeNode(5);
    node->left->right = new TreeNode(1);
    std::cout << sumNumbers(node);
    return 0;
}