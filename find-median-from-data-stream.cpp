#include "common.h"

std::priority_queue<int> pq_max;
std::priority_queue<int, std::vector<int>, std::greater<> > pq_min;

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
    }
}

double findMedian() {
    int size_min = pq_max.size();
    int size_max = pq_min.size();
    if (size_max == size_min ) {
        return (pq_max.top() + pq_min.top())/2.0;
    }
    else
        return pq_max.top();
}

int main() {
    addNum(1);
    addNum(2);
    std::cout << findMedian() << std::endl;
    addNum(3);
    std::cout << findMedian() << std::endl;
    return 0;
}
