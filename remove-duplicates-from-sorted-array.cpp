#include "common.h"
int removeDuplicates(vector<int>& nums) {
    int curr = 0;
    int k = 1;
    int prev = -1;
    while (curr < nums.size()) {
        if (prev >= 0) {
            int prev_val = nums[prev];
            while (prev_val == nums[curr]) {
                if (curr < nums.size()) curr++;
                if (curr == nums.size()) break;
            }
            if (curr == nums.size()) break;
            std::swap(nums[k], nums[curr]);
            k++;
            prev = k - 1;
            curr++;

        } else {
            curr++;
            prev = curr - 1;
        }
    }
    return k;
}

int main() {
    vector<int> inp = {1, 1, 2, 2, 4, 4, -2, -2, 4, -5, -6, -7, -7, -8, -8};
    std::sort(inp.begin(), inp.end());
    std::cout << removeDuplicates(inp) << "\n";
    std::cout << inp;
}