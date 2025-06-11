#include "common.h"

int maxProfit(vector<int>& prices) {
    int current_price = prices[0];
    int max_profit = 0;

    for (size_t i = 0; i < prices.size(); i++) {
        if (prices[i] - current_price > 0) {
            max_profit = std::max(max_profit, prices[i] - current_price);
        } else {
            current_price = prices[i];
        }
    }

    return max_profit;
}

int main()

{
    return 0;
}