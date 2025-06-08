#include "common.h"

int gcd(int k, int m) {
    if (k > m) std::swap(k, m);
    // m > k
    int res = m % k;
    if (res == 0) return k;
    return gcd(res, k);
}

void rotate_one(vector<int>& nums, int m, int k, int steps, int start) {
    int curr_index = start;
    for (int step = 0; step < steps - 1; step++) {
        int next_index = (curr_index - k + m) % m;
        std::swap(nums[next_index], nums[curr_index]);
        curr_index = next_index;
    }
}

void rotate(vector<int>& nums, int k) {
    int m = nums.size();
    if (k > m) k = k % m;
    if (k == 0) return;
    int d = gcd(m, k);
    int steps = m / d;
    for (int start = 0; start < d; start++) {
        rotate_one(nums, m, k, steps, start);
    }
}

int main() {
    // std::cout << gcd(17,19);
    std::vector<int> inp = {-1, -100, 3, 99};
    rotate(inp, 2);
    std::cout << inp;
    //
    return 0;
}