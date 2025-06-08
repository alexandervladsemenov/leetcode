#include "common.h"

int max_depth {0};

void maxDepth(TreeNode* root, int current_depth) {
    max_depth = std::max(max_depth, current_depth);
    if (root->left)
        maxDepth(root->left, current_depth + 1);
    if (root->right)
        maxDepth(root->right, current_depth + 1);
}

int maxDepth(TreeNode* root) {
    if (root == nullptr) {
        return max_depth;
    }
    max_depth = 1;
    int current_depth = max_depth;
    maxDepth(root, current_depth);
    return max_depth;
}



int main() {
    return 0;
}