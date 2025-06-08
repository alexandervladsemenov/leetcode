#include "common.h"

int rob(vector<int>& nums, int start) {
    if (nums.size() <= start) return 0;
    if (nums.size() - start == 1) return nums[start];
    if (nums.size() - start == 2) return max(nums[start], nums[start + 1]);
    if (nums.size() - start == 3)
        return max(nums[start] + nums[start + 2], nums[start + 1]);

    return max(rob(nums, start + 1), rob(nums, start + 2) + nums[start]);
}

int rob(vector<int>& nums) { return rob(nums, 0); }

int main() {
    std::vector<int> inp = {1, 2, 3, 1};

    std::cout << rob(inp) << "\n";
    inp = {2, 7, 9, 3, 1};
    std::cout << rob(inp) << "\n";
    return 0;
}