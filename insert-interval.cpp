#include "common.h"


std::pair<int, int> binarySearch(vector<vector<int> > &intervals, int number) {
    int start = 0, end = 2 * intervals.size() - 1;
    if (number > intervals[intervals.size() - 1][1])
        return {2 * intervals.size(), 2 * intervals.size()};
    if (number < intervals[0][0])
        return {-1, -1};
    while (end - start > 1) {
        int median = (start + end) / 2;
        int interval_index = median / 2;
        int interval_point = median % 2;
        if (intervals[interval_index][interval_point] > number) {
            end = median;
        } else {
            start = median;
        }
    }
    return {start, end};
}

vector<vector<int> > insert(vector<vector<int> > &intervals, vector<int> &newInterval) {
    if (intervals.empty())
        return {newInterval};
    const auto [start_p,end_p] = binarySearch(intervals, newInterval[0]);
    std::vector<std::vector<int> > answ;
    int start_index = 1;
    int start = intervals[0][0];
    int end = intervals[0][1];
    if (start_p == -1) {
        start_index = 0;
        start = newInterval[0];
        end = newInterval[1];
    }

    for (size_t i = start_index; i < intervals.size(); i++) {
        if (start_p / 2 == i - 1 && start_p != -1) {
            int val_st = newInterval[0];
            int val_end = newInterval[1];
            if (val_st > end) {
                answ.push_back({start, end});
                start = val_st;
                end = val_end;
            } else {
                end = std::max(val_end, end);
            }
        }
        int val_st = intervals[i][0];
        int val_end = intervals[i][1];
        if (val_st > end) {
            answ.push_back({start, end});
            start = val_st;
            end = val_end;
        } else {
            end = std::max(val_end, end);
        }
    }
    if (start_p / 2 == intervals.size() - 1 && start_p != -1) {
        int val_st = newInterval[0];
        int val_end = newInterval[1];
        if (val_st > end) {
            answ.push_back({start, end});
            start = val_st;
            end = val_end;
        } else {
            end = std::max(val_end, end);
        }
    }
    answ.push_back({start, end});
    if (start_p == 2 * intervals.size())
        answ.push_back(newInterval);
    return answ;
}

int main() {
    std::vector<std::vector<int> > intervals = {{1, 5}};
    vector newInterval = {0, 3};
    std::cout << insert(intervals, newInterval);
}
