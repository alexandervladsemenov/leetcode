#include "common.h"

int maxProfit(vector<int>& prices) {
    int current_price = prices[0];
    int max_profit = 0;
    std::vector<int> max_profits_from_start(prices.size());
    std::vector<int> max_profits_from_end(prices.size());
    for (size_t i = 0; i < prices.size(); i++) {
        if (prices[i] - current_price > 0) {
            max_profit = std::max(max_profit, prices[i] - current_price);
        } else {
            current_price = prices[i];
        }
        max_profits_from_start[i] = max_profit;
    }
    max_profit = 0;
    current_price = prices[prices.size() - 1];
    for (int i = prices.size() - 1; i >= 0; i--) {
        if (prices[i] - current_price < 0) {
            max_profit = std::max(max_profit, current_price - prices[i]);
        } else {
            current_price = prices[i];
        }
        max_profits_from_end[i] = max_profit;
    }
    max_profit = 0;

    for (size_t i = 0; i < prices.size(); i++) {
        max_profit = std::max(
            max_profits_from_end[i] + max_profits_from_start[i], max_profit);
    }

    return max_profit;
}

int main() { return 0; }