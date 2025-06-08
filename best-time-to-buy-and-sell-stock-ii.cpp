#include "common.h"
int maxProfit(vector<int>& prices)

{

int profit = 0;

int curr_price = prices[0];

for(int i{1} ; i < prices.size(); i++)
{
    if(curr_price > prices[i])
    {
        curr_price = prices[i];
        continue;
    }
    profit +=(prices[i] - curr_price);
    curr_price = prices[i];
    
}


return profit;    
}
int main()
{
    std::vector<int> prices = {7,6,4,3,1};
    std::cout << maxProfit(prices);
    return 0;
}