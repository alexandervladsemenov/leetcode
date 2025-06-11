#include "common.h"

bool containsNearbyDuplicate(vector<int> &nums, int k) {
    std::unordered_map<int, int> map;

    for (int i = 0; i < nums.size(); i++) {
        if (!map.contains(nums[i]))
            map[nums[i]] = i;
        else {
            if (const int index = map[nums[i]]; i - index <= k)
                return true;
            map[nums[i]] = i;
        }
    }
    return false;
}

int main() {
}
