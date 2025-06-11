#include  "common.h"


TreeNode *flatten_ret(TreeNode *node) {
    if (node == nullptr) {
        return nullptr;
    }
    auto left = node->left;
    auto right = node->right;
    if (right == nullptr && left == nullptr)
        return node;
    node->left = nullptr;
    auto end_left = flatten_ret(left);
    auto end_right = flatten_ret(right);
    TreeNode * ret_ptr = nullptr;
    if (left) {
        node->right = left;
        if (right)
        {
            end_left->right = right;
            ret_ptr = end_right;
        }
        else {
            ret_ptr = end_left;
        }
    } else {
        node->right = right;
        ret_ptr = end_right;
    }
    return ret_ptr;
}

void flatten(TreeNode *root) {
    flatten_ret(root);
}


int main()
{
    return 0;
}