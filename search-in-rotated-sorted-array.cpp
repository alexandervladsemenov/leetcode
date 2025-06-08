#include "common.h"

int gcd(int k, int m)
{
    if (k > m)
        std::swap(k, m);
    // m > k
    int res = m % k;
    if (res == 0)
        return k;
    return gcd(res, k);
}

void rotate_one(vector<int> &nums, int m, int k, int steps, int start)
{
    int curr_index = start;
    for (int step = 0; step < steps - 1; step++)
    {
        int next_index = (curr_index - k + m) % m;
        std::swap(nums[next_index], nums[curr_index]);
        curr_index = next_index;
    }
}

void rotate(vector<int> &nums, int k)
{
    int m = nums.size();
    if (k > m)
        k = k % m;
    if (k == 0)
        return;
    int d = gcd(m, k);
    int steps = m / d;
    for (int start = 0; start < d; start++)
    {
        rotate_one(nums, m, k, steps, start);
    }
}

int search(vector<int> &nums, int start, int end, int target)
{

    if (end - start > 1)
    {
        int median = (start + end) / 2;
        //
        bool med_to_end = nums[median] < nums[end];
        bool med_to_start = nums[median] > nums[start];
        // std::cout << start << " " <<  median << " " << end <<  std::endl;
        // std::cout << nums[start] << " " <<  nums[median] << " " << nums[end] << "\n" << std::endl;
        if (med_to_end && med_to_start)
        {
            if (target > nums[end] || target < nums[start])
            {
                return -1;
            }
            if (target > nums[median])
                return search(nums, median, end, target);
            else
                return search(nums, start, median, target);
        }
        else if (med_to_end)
        {
            if (target >= nums[median] && target <= nums[end])
                return search(nums, median, end, target);
            else
                return search(nums, start, median, target);
        }
        else if (med_to_start)
        {
            // std::cout << "It should be true " << std::endl;
            if (target <= nums[median] && target >= nums[start])
                return search(nums, start, median, target);
            else
                return search(nums, median, end, target);
        }
        else
        {
            return -1;
        }
    }
    else
    {
        if (nums[end] == target)
            return end;
        if (nums[start] == target)
            return start;
        return -1;
    }
}

int search(vector<int> &nums, int target)
{

    return search(nums, 0, nums.size() - 1, target);
}

int main()
{
    std::vector<int> inp = {1,3,4,6,9,-2,-5,-6,-8,-9,12,345};
    std::sort(inp.begin(),inp.end());
    rotate(inp,4);
    std::cout << inp << "\n";
    int targert = -5;
    std::cout << search(inp, targert) << "\n";
    return 0;
}