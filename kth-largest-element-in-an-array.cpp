#include "common.h"


int findKthLargest(vector<int>& nums, int k) {
        std::priority_queue<int, std::vector<int>, std::greater<int>> pq;
        for (size_t i = 0; i < nums.size(); i++) {
                if (pq.size() < k) {
                        pq.push(nums[i]);
                }
                else if (pq.top() < nums[i]) {
                        pq.pop();
                        pq.push(nums[i]);
                }
        }
        return pq.top();
}




int main() {

        std::vector<int> nums = {1,2,3,4,5,6,7,8,9,10};
        int k = 3;
        std::cout << findKthLargest(nums, k);
        return 0;
}