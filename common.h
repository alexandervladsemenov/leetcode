#ifndef COMMON_H
#define COMMON_H
#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
#include <algorithm>
#include <array>
#include <cstdint>
#include <optional>
#include <bits/locale_facets_nonio.h>

using namespace std;
template<typename, typename = void>
constexpr bool is_iterable{};

template<typename T>
constexpr bool is_iterable<T, std::void_t<decltype(std::declval<T>().begin()),
            decltype(std::declval<T>().end())> > =
        true;

template<typename V,
    enable_if_t<is_iterable<V> && !is_same_v<V, string>, bool>  = true>
std::ostream &operator<<(std::ostream &os, const V &data) noexcept {
    for (auto it = data.begin(); it != data.end(); it++) {
        os << *it << " ";
    }

    return os;
}

class RollingHash {
    std::vector<long long> hashes;
    static std::vector<long long> powers;
    long long hash{0};
    uint32_t module;

public:
    RollingHash(uint32_t base, uint32_t module, const std::string &str, int index = -1) : module(module) {
        if (powers.size() < str.length()) {
            powers.resize(str.length());
            powers[0] = 1;
            for (size_t i{1}; i < str.length(); i++) {
                powers[i] = (powers[i - 1] * base) % module;
                powers[i] %= module;
            }
            // std::cout << powers.size() << "\n";
        }

        if (index == -1) // single hash
        {
            hash = (str[0] - 'a' + 1) % module;
            for (size_t i{1}; i < str.length(); i++) {
                hash += (powers[i] * (str[i] - 'a' + 1)) % module;
                hash %= module;
            }
        } else {
            hashes.resize(str.length());
            hashes[0] = (str[0] - 'a' + 1) % module;
            for (size_t i{1}; i < str.length(); i++) {
                hashes[i] = hashes[i - 1] + (powers[i] * (str[i] - 'a' + 1)) % module;
                hashes[i] %= module;
            }
            // std::cout << hashes << "\n";
        }
    }

    long long operator()(size_t index) {
        if (!hashes.empty())
            return hashes[index];
        else
            return (hash * powers[index]) % module;
    }
};

std::vector<long long> RollingHash::powers = {};


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {
    }

    explicit TreeNode(const int x) : val(x), left(nullptr), right(nullptr) {
    }

    TreeNode(const int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {
    }
};

struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {
    }

    ListNode(int x) : val(x), next(nullptr) {
    }

    ListNode(int x, ListNode *next) : val(x), next(next) {
    }
};

template<typename T, typename U>
void remove_element_from_multimap(std::multimap<T, U> &map_, T key, U value) {
    auto iterpair = map_.equal_range(key);
    auto it = iterpair.first;
    for (; it != iterpair.second; ++it) {
        if (it->second == value) {
            map_.erase(it);
            break;
        }
    }
}


template<typename Comparison = std::less<int> >
struct Heap {
    std::vector<int> data;
    std::multimap<int, int> val_index;
    Comparison comparison;

    Heap() = default;

    explicit Heap(const std::vector<int> &data_arr) {
        for (const auto &elem: data_arr) {
            add(elem);
        }
    }

    void heapify_up(int index, int val) {
        if (index == 0)
            return;
        int parent = (index - 1) / 2;
        if (comparison(data[parent], val)) {
            remove_element_from_multimap(val_index, data[parent], parent);
            remove_element_from_multimap(val_index, val, index);
            val_index.insert({val, parent});
            val_index.insert({data[parent], index});
            std::swap(data[parent], data[index]);
            heapify_up(parent, val);
        }
    }

    void heapify_down(int index, int val) {
        if (index == data.size() - 1)
            return;
        int left_child = 2 * index + 1;
        int right_child = 2 * index + 2;
        if (left_child < data.size()) {
            int left_val = data[left_child];

            int max_val = left_val;
            if (comparison(left_val, val))
                max_val = val;;
            if (right_child < data.size()) {
                if (comparison(max_val, data[right_child]))
                    max_val = data[right_child];;
            }
            if (max_val == val) return;
            if (max_val == left_val) {
                // swap left and parent
                remove_element_from_multimap(val_index, left_val, left_child);
                remove_element_from_multimap(val_index, val, index);
                val_index.insert({val, left_child});
                val_index.insert({left_val, index});
                std::swap(data[left_child], data[index]);
                heapify_down(left_child, val);
            } else {
                // it's the right child
                remove_element_from_multimap(val_index, data[right_child], right_child);
                remove_element_from_multimap(val_index, val, index);
                val_index.insert({val, right_child});
                val_index.insert({data[right_child], index});
                std::swap(data[right_child], data[index]);
                heapify_down(right_child, val);
            }
        } else
            return;
    }


    void add(int val) {
        data.push_back(val);
        val_index.insert({val, int(data.size() - 1)});
        heapify_up(data.size() - 1, val);
    }

    void remove(int val) {
        auto index = val_index.find(val)->second;
        data[index] = data[data.size() - 1];
        data.pop_back();
        remove_element_from_multimap(val_index, val, index);
        //
        int parent = (index - 1) / 2;
        if (comparison(data[parent], val))
            heapify_up(index, val);
        else
            heapify_down(index, val);
    }

    void add_remove(int add_val, int remove_val) {
        int index = val_index.find(remove_val)->second;
        data[index] = add_val;
        remove_element_from_multimap(val_index, remove_val, index);
        val_index.insert({add_val, index});
        int parent = (index - 1) / 2;
        if (comparison(data[parent], add_val))
            heapify_up(index, add_val);
        else
            heapify_down(index, add_val);
    }

    int top() {
        return data[0];
    }
    void pop() {
        remove(top());
    }
};


#endif
