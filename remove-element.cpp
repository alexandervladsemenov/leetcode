#include "common.h"
int removeElement(vector<int>& nums, int val) {
    int k = 0;
    int curr = 0;
    while (curr < nums.size()) {
        while (nums[curr] == val) {
            if (curr < nums.size()) curr++;
            if (curr == nums.size()) break;
        }
        if (curr == nums.size()) break;
        std::swap(nums[k], nums[curr]);
        k++;
        curr++;
    }
    return k;
}
int main() {
    vector<int> arr = {3, 3, 2, 1, 4, 2, 3, 3, 3, 3, 4, 2, 4};
    int val = 3;
    std::cout << removeElement(arr, val) << "       ";
    std::cout << arr;
    return 0;
}