#include "common.h"

bool canJump(vector<int>& nums) {
    int max_jump = 0;
    if (nums.size() == 1) return true;
    for (int i{0}; i < nums.size(); i++) {
        max_jump = max(max_jump, i + nums[i]);
        if (max_jump == nums.size() - 1) return true;
        if (max_jump <= i) {
            return false;
        }
    }
    return true;
}

int main() {
    std::vector<int> inp = {3, 2, 1, 0, 4};
    std::cout << canJump(inp);
    return 0;
}