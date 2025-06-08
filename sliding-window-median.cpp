#include "common.h"




int main() {
    std::vector<int> test_data = {2,3,4,-1,2,4,-10};
    Heap maxHeap_test(test_data);
    maxHeap_test.add(5);
    maxHeap_test.remove(3);

    return 0;
}
