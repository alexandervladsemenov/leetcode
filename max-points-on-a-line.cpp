#include "common.h"

int gcd(int k, int m) {
    if (k > m) std::swap(k, m);
    // m > k
    int res = m % k;
    if (res == 0) return k;
    return gcd(res, k);
}

std::unordered_map<std::pair<std::pair<int, int>, std::pair<int, int>>,
                   std::pair<int, int>>
    counts;

std::pair<std::pair<int, int>, std::pair<int, int>> find_offset_intersect(
    int x1, int x2, int y1, int y2) {
    int gcd_pair = gcd(std::abs(y2 - y1), std::abs(x2 - x1));
    int k_numerator = (y2 - y1) / gcd_pair;
    int k_denominator = (x2 - x1) / gcd_pair;
    int gcd_offset = gcd(std::abs(y1 * x2 - y2 * x1), std::abs(x2 - x1));
    int offset_numerator = (y1 * x2 - y2 * x1) / gcd_offset;
    int offset_denominator = (x2 - x1) / gcd_offset;
    return {{k_numerator, k_denominator},
            {offset_numerator, offset_denominator}};
}

int maxPoints(vector<vector<int>>& points) {
    int max_points = 0;
    size_t n = points.size();
    for (size_t i = n - 1; i >= 0; i--) {
        for (size_t j = 0; j < i; j++) {
            auto& vec1 = points[i];
            auto& vec2 = points[j];
            int x1 = vec1[0];
            int y1 = vec1[1];
            int x2 = vec2[0];
            int y2 = vec2[1];
            auto key = find_offset_intersect(x1, x2, y1, y2);
            if (counts.count(key) == 0) {
                counts[key] = {2, i};
                max_points = max(max_points, 2);
            } else {
                auto [count_, i_p] = counts[key];
                if (i_p == i) {
                    count_++;
                    counts[key] = {count_, i};
                    max_points = max(max_points, count_);
                }
            }
        }
    }

    return max_points;
}
int main() { return 0; }