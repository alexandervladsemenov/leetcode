#include "common.h"


int maxProduct(int *arr, int size) {
    if (size <= 0)
        return -10;
    int first_minus{-1}, last_minus{-1}, number_of_minuses{0};
    for (int i = 0; i < size; i++) {
        if (arr[i] < 0) {
            if (first_minus < 0) {
                first_minus = i;
            }
            last_minus = i;
            number_of_minuses++;
        }
    }
    int ans = 1;
    if (number_of_minuses % 2 == 0) {
        for (int i = 0; i < size; i++) {
            ans *= arr[i];
        }
    } else {
        int ans_first = 1;
        int ans_last = 1;
        int ans_middle = 1;
        for (int i = 0; i <= first_minus; i++) {
            ans_first *= arr[i];
        }
        for (int i = last_minus; i < size; i++) {
            ans_last *= arr[i];
        }
        for (int i = first_minus + 1; i < last_minus; i++) {
            ans_middle *= arr[i];
        }
        if (number_of_minuses > 1)
            ans = max(ans_middle * ans_first, ans_middle * ans_last);
        else {
            int max_first = first_minus == 0 ? arr[first_minus] : ans_first / arr[first_minus];
            int max_second = last_minus == size - 1 ? arr[first_minus] : ans_last / arr[first_minus];
            ans = max(max_first, max_second);
        }
    }


    return ans;
}

int maxProduct(vector<int> &nums) {
    int max_val = -10;
    int start = 0;
    int len = nums.size();
    for (size_t i = 0; i < nums.size(); i++) {
        if (nums[i] == 0) {
            max_val = max(max_val, maxProduct(nums.data() + start, i - start));
            max_val = max(max_val, 0);
            start = i + 1;
        }
    }
    max_val = max(max_val, maxProduct(nums.data() + start, len - start));
    return max_val;
}

int main() {
    std::vector<int> nums{-2, 1, -4, 0, -1};
    std::cout << maxProduct(nums) << std::endl;
    return 0;
}
