#include "common.h"

std::unordered_map<int, int> indexes_inorder;
std::unordered_map<int, int> indexes_preoder;

// start and end indexes in preorder array
void buildTree(TreeNode *node, vector<int> &preorder, vector<int> &inorder, int root_value, int start_index_preorder,
               int end_index_preorder, int start_index_indorder,
               int end_index_inroder) {
    if (start_index_indorder >= end_index_inroder || start_index_preorder >= end_index_preorder)
        return;
    // the goal is to find roots of left/right children
    int root_inorder_index = indexes_inorder[root_value];
    // left child is missing
    if (root_inorder_index == start_index_indorder) {
        int right_child = preorder[start_index_preorder + 1];
        node->right = new TreeNode(right_child);
        buildTree(node->right, preorder, inorder, right_child, start_index_preorder + 1, end_index_preorder,
                  start_index_indorder + 1, end_index_inroder);
    }
    // right child is missing
    if (root_inorder_index == end_index_inroder) {
        int left_child = preorder[start_index_preorder + 1];
        node->left = new TreeNode(left_child);
        buildTree(node->left, preorder, inorder, left_child, start_index_preorder + 1, end_index_preorder,
                  start_index_indorder, end_index_inroder - 1);
    }
    // both right and left are present
    if (root_inorder_index != start_index_indorder && root_inorder_index != end_index_inroder) {
        int left_child = preorder[start_index_preorder + 1];
        int end_index_left_inorder = root_inorder_index - 1;
        int start_index_left_inorder = start_index_indorder;
        int start_index_left_preorder = start_index_preorder + 1;
        int end_index_left_preorder = start_index_left_preorder + end_index_left_inorder - start_index_left_inorder;
        if (end_index_left_preorder - start_index_left_preorder != end_index_left_inorder - start_index_left_inorder) {
            std::cout << "-E-: critical error at " << __FILE__ << " line " << __LINE__ << std::endl;
            std::cout << "Root = " << root_value << " left child " << left_child << std::endl;
            exit(1);
        } else {
            node->left = new TreeNode(left_child);
            buildTree(node->left, preorder, inorder, left_child, start_index_left_preorder, end_index_left_preorder,
                      start_index_left_inorder, end_index_left_inorder);
        }

        int right_child = preorder[start_index_preorder + 2 + end_index_left_inorder - start_index_left_inorder];
        int end_index_right_inorder = end_index_inroder;
        int end_index_right_preorder = end_index_preorder;
        int start_index_right_inorder = root_inorder_index + 1;
        int start_index_right_preorder = indexes_preoder[right_child];
        if (end_index_right_inorder - start_index_right_inorder != end_index_right_preorder -
            start_index_right_preorder) {
            std::cout << "-E-: critical error at " << __FILE__ << " line " << __LINE__ << std::endl;
            std::cout << "Root = " << root_value << " right child " << right_child << std::endl;
            exit(1);
        } else {
            node->right = new TreeNode(right_child);
            buildTree(node->right, preorder, inorder, right_child, start_index_right_preorder, end_index_right_preorder,
                      start_index_right_inorder, end_index_right_inorder);
        }
    }
}

TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
    if (preorder.empty())
        return nullptr;
    for (int i = 0; i < inorder.size(); ++i) {
        indexes_inorder[inorder[i]] = i;
    }
    for (int i = 0; i < inorder.size(); ++i) {
        indexes_preoder[preorder[i]] = i;
    }
    int root_v = preorder[0];
    auto root = new TreeNode(root_v);
    int start_index = 0;
    int end_index = inorder.size() - 1;
    buildTree(root, preorder, inorder, root_v, start_index, end_index, start_index, end_index);
    return root;
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
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(1);
    root->right = new TreeNode(4);
    std::vector<int> preorder;
    std::vector<int> inorder;
    preorder_traversal(root, preorder);
    inorder_traversal(root, inorder);
    std::cout << inorder << std::endl;
    std::cout << preorder << std::endl;
    auto new_tree = buildTree(preorder, inorder);
    std::cout << isSameTree(root, new_tree) << std::endl;
}
