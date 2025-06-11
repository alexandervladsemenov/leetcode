#include "common.h"


vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    std::vector<int> result;
    std::deque<int> window;
    for (int i = 0; i < k; i++) {
        while (!window.empty() && nums[window.back()] < nums[i]) {
           window.pop_back();
        }
        window.push_back(i);
    }
    result.push_back(nums[window.front()]);
    for (int i = k ; i < nums.size(); i++) {
        if (window.front() < i - k + 1 ) {
            window.pop_front();
        }
        while (!window.empty() && nums[window.back()] < nums[i]) {
            window.pop_back();
        }
        window.push_back(i);
        result.push_back(nums[window.front()]);

    }

    return result;
}


int main() {
    std::vector<int> nums ={ 1,3,-1,-3,5,3,6,7};
    maxSlidingWindow(nums, 3);
    return 0;
}