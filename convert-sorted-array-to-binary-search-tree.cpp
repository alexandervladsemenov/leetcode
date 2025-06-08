#include "common.h"


void sortedArrayToBST(TreeNode **node, vector<int> &nums, int start, int end) {
    if (end - start > 0) {
        int median = (start + end) / 2;
        *node = new TreeNode(nums[median]);
        sortedArrayToBST(&(*node)->left, nums, start, median - 1);
        sortedArrayToBST(&(*node)->right, nums, median + 1, end);
    } else if (end == start) {
        *node = new TreeNode(nums[start]);
    }
}

TreeNode *sortedArrayToBST(vector<int> &nums) {
    if (nums.empty())
        return nullptr;
    TreeNode *root = nullptr;
    int start = 0, end = nums.size() - 1;
    sortedArrayToBST(&root, nums, start, end);
    return root;
}


int main() {
    std::vector<int> nums = {-10, -3, 0, 5, 9};
    auto answer = sortedArrayToBST(nums);
    return 0;
}
