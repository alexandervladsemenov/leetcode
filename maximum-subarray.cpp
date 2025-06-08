#include "common.h"

int maxSubArray(vector<int>& nums) {
    int sum = 0;
    int max_sum = -10e4;
    for (const int num : nums) {
        sum += num;
        if (max_sum < sum) {
            max_sum = sum;
        }
        if (sum < 0) {
            sum = 0;
        }
    }
    return max_sum;
}



int main() {
    std::vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};
    std::cout << maxSubArray(nums);
    return 0;
}