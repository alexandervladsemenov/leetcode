#include "common.h"

class Median {
    Heap<less<> > pq_max;
    Heap<greater<> > pq_min;

public:
    void addNum(int num) {
        int size_max = pq_max.size();
        int size_min = pq_min.size();
        if (size_max == 0 && size_min == 0) {
            pq_max.push(num);
            return;
        }

        if (size_min == size_max) {
            int top_min = pq_min.top(); // minimum element of the second half
            if (top_min > num) {
                pq_max.push(num);
            } else {
                pq_min.pop();
                pq_min.push(num);
                pq_max.push(top_min);
            }
        }
        if (size_min < size_max) {
            int top_max = pq_max.top(); // maximum element of the first half
            // we should add to min
            if (num > top_max)
                pq_min.push(num);
            else {
                pq_max.pop();
                pq_min.push(top_max);
                pq_max.push(num);
            }
        } else if (size_max < size_min) {
            int top_min = pq_min.top();
            // we should add to max
            if (num > top_min) {
                pq_min.pop();
                pq_min.push(num);
                pq_max.push(top_min);
            } else {
                pq_max.push(num);
            }
        }
    }

    void removeNum(int remove_number) {
        bool remove_max = false;
        bool remove_min = false;
        remove_max = pq_max.find(remove_number);
        remove_min = pq_min.find(remove_number);
        if (remove_max && remove_min) {
            remove_max = remove_max & (pq_max.size() > pq_min.size());
            remove_min = remove_min & (pq_max.size() < pq_min.size());
        }


        if (remove_max) {
            pq_max.remove(remove_number);
            int top_min = pq_min.top();
            pq_min.pop();
            addNum(top_min);
        }
        if (remove_min) {
            pq_min.remove(remove_number);
            int top_max = pq_max.top();
            pq_max.pop();
            addNum(top_max);
        }
    }

    Median() = default;

    Median(vector<int> &nums, int k) {
        for (int i = 0; i < k; i++) {
            addNum(nums[i]);
        }
    }

    void add_remove(int add, int remove) {
        addNum(add);
        removeNum(remove);
    }

    double findMedian() {
        int size_max = pq_max.size();
        int size_min = pq_min.size();
        if (size_max == size_min) {
            return (pq_max.top() + pq_min.top()) / 2.0;
        } else if (size_max > size_min)
            return pq_max.top();
        else
            return pq_min.top();
    }
};


double find_meadian_brute_force(int *arr, int start, int end) {
    int *arr_copy = new int[end - start + 1];
    std::copy(arr + start, arr + end + 1, arr_copy);
    std::sort(arr_copy, arr_copy + end - start + 1);
    int mid = (end - start) / 2;
    int mid2 = mid + 1;
    double median;
    if ((end -start) % 2 == 0)
        median =  arr_copy[mid];
    else
        median = (arr_copy[mid2 ]  + arr_copy[mid])/2.0;
    delete[] arr_copy;
    return median;
}

int main() {
    std::vector<int> test_data = {
        1,3,-1,-3,5,3,6,7
    };
    int k = 3;
    int start = 0, end = k - 1;
    Median median(test_data,k);
    for ( int i = 0; i < test_data.size() - k; i++ ) {
        double median_brute_force = find_meadian_brute_force(test_data.data(), start, end);
        double median_optimized = median.findMedian();
        std::cout << median_brute_force << " vs " << median_optimized << std::endl;
        median.add_remove(test_data[end+1], test_data[start]);
        start++;
        end++;
    }
    return 0;
}
