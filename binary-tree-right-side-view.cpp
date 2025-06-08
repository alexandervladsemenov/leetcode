#include "common.h"


void bfs_tree(TreeNode *node) {
    if (node == nullptr) {
        return;
    }

    std::queue<TreeNode *> q;
    q.push(node);
    int depth = 0;
    std::vector<int> right_view;
    while (!q.empty()) {
        size_t count = q.size();
        for (size_t i = 0; i < count; i++) {
            auto p= q.front();
            if (p->left) {
                q.push(p->left);
            }
            if (p->right) {
                q.push(p->right);
            }
            q.pop();
            std::cout << p->val << " ";
            if (i == count - 1) {
                right_view.push_back(p->val);
            }
        }
        depth++;
        std::cout <<"depth = " << depth << "\n";
    }
}

int main() {
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(1);
    root->right = new TreeNode(4);
    bfs_tree(root);
    return 0;
}
