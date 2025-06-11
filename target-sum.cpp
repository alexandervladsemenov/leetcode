#include "common.h"


int findTargetSumWays(vector<int>& nums, int target, int start) {

    if (start == nums.size() - 1) {
        if (target == 0 && nums[start] == 0)
            return 2;
        if (target == nums[start]) {
            return 1;
        }
        if (target == -nums[start]) {
            return 1;
        }
        return 0;
    }

    int num = nums[start];
    int target_plus = num + target;
    int target_minus = target - num;
    return findTargetSumWays(nums, target_plus, start + 1) +findTargetSumWays(nums, target_minus, start + 1) ;

}

int findTargetSumWays(vector<int>& nums, int target) {
    return findTargetSumWays(nums,target,0);
}

int main() {
    std::vector<int> nums = {7,9,3,8,0,2,4,8,3,9};
    int target = 0;
    std::cout << findTargetSumWays(nums,target);
    return 0;
}