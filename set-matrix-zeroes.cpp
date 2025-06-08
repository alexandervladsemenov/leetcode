#include "common.h"

void setZeroes(vector<vector<int> > &matrix) {
    int min_val = matrix[0][0];
    for (const auto &vec: matrix)
        for (auto &x: vec) {
            min_val = std::min(x, min_val);
        }

    min_val -= 1;
    for (size_t i = 0; i < matrix.size(); i++) {
        for (size_t j = 0; j < matrix[i].size(); j++) {
            if (matrix[i][j] == 0) {
                for (auto &k: matrix) {
                    if (k[j] != 0)
                        k[j] = min_val;
                }
                for (int &k: matrix[i]) {
                    if (k != 0)
                        k = min_val;
                }
            }
        }
    }
    for (auto & i : matrix) {
        for (int & j : i) {
            if (j == min_val) {
                j = 0;
            }
        }
    }
}


int main() {
    return 0;
}
