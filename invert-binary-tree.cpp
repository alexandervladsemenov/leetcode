#include "common.h"


TreeNode *invertTree(TreeNode *root) {
    if (root == nullptr)
        return root;
    auto left = root->left;
    auto right = root->right;
    auto temp = right;
    right = left;
    left = temp;
    root->left = invertTree(left);
    root->right = invertTree(right);
    return root;
}

int main() {
    return 0;
}
