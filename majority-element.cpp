#include "common.h"

int majorityElement(vector<int>& nums) {
    int el = nums[0];
    int counter = 0;
    for (int num : nums) {
        if (counter == 0) {
            counter++;
            el = num;
            continue;
        }

        if (el == num) {
            counter++;
        } else {
            counter--;
        }
    }
    return el;
}

int main() {
    std::vector<int> inp = {2, 3, 3, 2};

    std::cout << majorityElement(inp);

    return 0;
}