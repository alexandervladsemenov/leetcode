#include "common.h"

int climbStairs(int n) {
    if (n == 1) return 1;
    if (n == 2) return 2;
    if (n == 0) return 0;
    return climbStairs(n - 1) + climbStairs(n - 2);
}

int main() {

    std::cout << climbStairs(45) << "\n";
}