#include "common.h"

// Define a custom comparison function object (functor)
struct CompareAscending
{
    bool operator()(vector<int> a, vector<int> b) const
    {
        return a[0] < b[0]; // Sort in ascending order
    }
};

vector<vector<int>> merge(vector<vector<int>> &intervals)
{
    if(intervals.empty())
        return {};
    std::sort(intervals.begin(),intervals.end(),CompareAscending());
    std::vector<std::vector<int>> answ;
    int start = intervals[0][0];
    int end = intervals[0][1];
    for(size_t i = 1; i < intervals.size(); i ++)
    {
        int val_st = intervals[i][0];
        int val_end = intervals[i][1]; 
        if(val_st > end)
        {
            answ.push_back({start,end});
            start = val_st;
            end = val_end;
        }
        else
        {
            end = std::max(val_end,end);
        }
    }
    answ.push_back({start,end});
    return answ;
}

int main()
{
    return 0;
}