#include "common.h"
int countWhileMergeSort(vector<long>& prefix, int left, int right, int lower, int upper) {
    if (right - left <= 1) return 0;
    int mid = (left + right) / 2;
    int count = countWhileMergeSort(prefix, left, mid, lower, upper) +
                countWhileMergeSort(prefix, mid, right, lower, upper);

    int j = mid, k = mid, t = mid;
    vector<long> cache(right - left);
    int r = 0;

    for (int i = left; i < mid; ++i) {
        while (k < right && prefix[k] - prefix[i] < lower) k++;
        while (j < right && prefix[j] - prefix[i] <= upper) j++;
        while (t < right && prefix[t] < prefix[i]) cache[r++] = prefix[t++];
        cache[r++] = prefix[i];
        count += j - k;
    }

    copy(cache.begin(), cache.begin() + r, prefix.begin() + left);
    return count;
}


int countRangeSum(vector<int>& nums, int lower, int upper) {
    int n = nums.size();
    vector<long> prefix(n + 1, 0);
    for (int i = 0; i < n; ++i) {
        prefix[i + 1] = prefix[i] + nums[i];
    }
    return countWhileMergeSort(prefix, 0, n + 1, lower, upper);
}

int main() {

}