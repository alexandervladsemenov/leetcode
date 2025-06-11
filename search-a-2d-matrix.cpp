#include  "common.h"


bool searchMatrix(vector<vector<int> > &matrix, int target) {
    size_t n = matrix.size();
    size_t m = matrix[0].size();
    int start = 0;
    int end = n * m - 1;
    if (matrix[n - 1][m - 1] == target)
        return true;
    if (matrix[0][0] == target)
        return true;
    while (end - start > 1) {
        int mid = (start + end) / 2;

        int row = mid / m;
        int col = mid % m;
        if (matrix[row][col] == target)
            return true;
        if (matrix[row][col] > target)
            end = mid;
        if (matrix[row][col] < target)
            start = mid;
    }
    std::cout << " \n";
    return false;
}


int main() {
    std::vector<std::vector<int> > matrix = {{1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 60}};
    std::cout << "\n" << searchMatrix(matrix, 15) << "\n";
}
