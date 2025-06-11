#include "common.h"


int maxSubarraySumCircular(vector<int> &nums) {
    int sum_inverted = 0;
    int sum = 0;
    int max_sum_inverted = -30e4;
    int max_sum = max_sum_inverted;
    int total_sum = 0;
    for (const int num : nums) {
        sum_inverted += -num;
        sum+=num;
        total_sum+=num;
        if (max_sum_inverted < sum_inverted) {
            max_sum_inverted = sum_inverted;
        }
        if(max_sum < sum)
        {   
            max_sum = sum;
        }
        if (sum_inverted < 0) {
            sum_inverted = 0;
        }
        if (sum < 0) {
            sum = 0;
        }
    }
    if(max_sum < 0)
        return max_sum;
    

    return std::max(max_sum,total_sum + max_sum_inverted);
}


int main() {
    std::vector<int> nums = {5,-3,-4,1,2,10,-9,5};
    std::cout << maxSubarraySumCircular(nums);
    return 0;
}
