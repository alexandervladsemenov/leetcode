#include "common.h"

vector<string> summaryRanges(vector<int> &nums)
{
    if (nums.size() == 0)
        return {""};
    std::vector<std::string> ans;
    int start = nums[0];
    int end = nums[0];
    for (size_t i = 1; i < nums.size(); i++)
    {
        if (end == nums[i] - 1)
        {
            end = nums[i];
        }
        else
        {
            char ret[256];
            if (start != end)
                sprintf(ret, "%d->%d", start, end);
            else
                sprintf(ret, "%d", start, end);
            ans.push_back(ret);
            start = nums[i];
            end = nums[i];
        }
    }
    char ret[256];
    if (start != end)
        sprintf(ret, "%d->%d", start, end);
    else
        sprintf(ret, "%d", start, end);
    ans.push_back(ret);
    return ans;
}

int main()
{
    std::vector<int> nums = {0, 2, 3, 4, 6, 8, 9};
    auto ans = summaryRanges(nums);
    for (auto an : ans)
    {
        std::cout << an << "\n";
    }
    return 0;
}