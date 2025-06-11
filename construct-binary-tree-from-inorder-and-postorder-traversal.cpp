#include  "common.h"

std::unordered_map<int, int> indexes_inorder;
std::unordered_map<int, int> indexes_postorder;







TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {

}




void preorder_traversal(TreeNode *root, std::vector<int> &preorder) {
    if (root == nullptr)
        return;
    preorder.push_back(root->val);
    preorder_traversal(root->left, preorder);
    preorder_traversal(root->right, preorder);
}


void inorder_traversal(TreeNode *root, std::vector<int> &inorder) {
    if (root == nullptr)
        return;
    inorder_traversal(root->left, inorder);
    inorder.push_back(root->val);
    inorder_traversal(root->right, inorder);
}


void postorder_traversal(TreeNode *root, std::vector<int> &postorder) {
    if (root == nullptr)
        return;
    postorder_traversal(root->left, postorder);
    postorder_traversal(root->right, postorder);
    postorder.push_back(root->val);
}

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
    return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}


int main() {


    return 0;
}