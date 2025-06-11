#include "common.h"


void merge(ListNode **start, ListNode **end, int size) {
    int counter = 0;
    if (size <= 1)
        return;

    ListNode *median = nullptr;
    for (auto it = *start; it != nullptr; it = it->next) {
        if (counter == (size - 1) / 2) {
            median = it;
            break;
        }
        counter++;
    }
    int size_1 = counter + 1;
    int size_2 = size - size_1;
    ListNode *temp = median->next;
    median->next = nullptr;
    merge(start, &median, size_1);
    merge(&temp, end, size_2);
    auto cur1 = *start;
    auto cur2 = temp;
    ListNode *cur = nullptr;
    for (int i = 0; i < size; i++) {
        if (cur == nullptr) {
            if (cur1->val > cur2->val) {
                cur = cur2;
                cur2 = cur2->next;
                *start = cur;
            } else {
                cur = cur1;
                cur1 = cur1->next;
            }
        }
        if (cur1 == nullptr && cur2 == nullptr) {
            cur->next = nullptr;
            break;
        } else if (cur1 == nullptr) {
            cur->next = cur2;
            cur2 = cur2->next;
            cur = cur->next;
        } else if (cur2 == nullptr) {
            cur->next = cur1;
            cur1 = cur1->next;
            cur = cur->next;
        } else {
            if (cur1->val > cur2->val) {
                cur->next = cur2;
                cur2 = cur2->next;
                cur = cur->next;
            } else {
                cur->next = cur1;
                cur1 = cur1->next;
                cur = cur->next;
            }
        }
    }
}

ListNode *sortList(ListNode *head) {
    int size = 0;
    for (auto it = head; it != nullptr; it = it->next) {
        size++;
    }
    int start_c = 0;
    int end_c = size - 1;
    int counter = 0;
    ListNode *start = nullptr;
    ListNode *end = nullptr;
    for (auto it = head; it != nullptr; it = it->next) {
        if (counter == start_c) {
            start = it;
        }
        if (counter == end_c) {
            end = it;
        }
        counter++;
    }
    merge(&start, &end, size);

    return start;
}


ListNode *createLlistFromVector(const std::vector<int> &vec) {
    ListNode *head = nullptr;
    if (vec.empty()) {
        return head;
    }
    head = new ListNode(vec[0]);
    auto node = head;
    for (size_t i = 1; i < vec.size(); i++) {
        node->next = new ListNode(vec[i]);
        node = node->next;
    }
    return head;
}

int main() {
    auto answer = createLlistFromVector({11, 4, 5, 6, 8, 0, -4, 9, 12, -1, -20, 1, 10, -1});
    auto sortedList = sortList(answer);
    return 0;
}
