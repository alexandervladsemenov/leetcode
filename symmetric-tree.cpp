#include "common.h"

bool isSameTree(TreeNode *p, TreeNode *q) {
    if (p == nullptr && q == nullptr)
        return true;
    if (p == nullptr)
        return false;
    if (q == nullptr)
        return false;
    if (p->val != q->val) {
        return false;
    }
    return isSameTree(p->left, q->right) && isSameTree(p->right, q->left);
}


bool isSymmetric(TreeNode *root) {
    return isSameTree(root, root);
}


int main() {
    return 0;
}
