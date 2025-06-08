#include "common.h"

    void merge(vector<int>& nums1, int m, const vector<int>& nums2, const int n) {
            vector<int> out(n + m);
    int i1{0};
    int i2{0};
    int i_total = 0;
    if(nums2.empty())
        return;
    while (i_total < n + m) {
        if (i2 == n || (nums1[i1] < nums2[i2] && i1 < m)) {
            out[i_total] = nums1[i1];
            i1++;
        } else {
            out[i_total] = nums2[i2];
            i2++;
        }
        i_total++;
    }
    nums1 = out;
    }

int main() {
    std::vector nums1 = {1, 2, 3, 0, 0, 0};
    std::vector nums2 = {2, 5, 6};
    merge(nums1,3,nums2,3);
    std::cout << nums1;
    return 0;
}