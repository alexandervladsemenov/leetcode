//
// Created by Alexander Semenov on 6/3/2025.
//

#include "common.h"

std::vector<int> findDuplicates(std::vector<int>& nums) {
    std::vector<int> duplicates;
    for (int i = 0; i < nums.size(); ++i) {
        int idx = std::abs(nums[i]) - 1;
        if (nums[idx] < 0) {
            duplicates.push_back(std::abs(nums[i]));
        } else {
            nums[idx] = -nums[idx];
        }
    }
    return duplicates;
}

int main() {
    std::vector<int> nums = {4, 3, 2, 7, 8, 2, 3, 1};

    std::cout << findDuplicates(nums) << std::endl;
    return 0;
}
