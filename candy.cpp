#include "common.h"

int candy(vector<int> &ratings)
{
    std::optional<int> height_max;
    std::optional<int> pos_max;
    int prev_candy = 0;
    int sum = 0;

    for (int i{0}; i < ratings.size(); i++)
    {
        if (i == 0)
        {
            sum = 1;
            prev_candy = 1;
            continue;
        }
        auto rate_prev = ratings[i - 1];
        auto rate_current = ratings[i];
        if (rate_current > rate_prev)
        {
            height_max.reset();
            pos_max.reset();
            prev_candy++;
            sum += prev_candy;
        }
        else if (rate_current < rate_prev)
        {
            if (height_max.has_value())
            {
                prev_candy = 1;
                int dist = i - pos_max.value();
                int height = height_max.value();
                if (height >= 1 + dist)
                {
                    sum += (dist);
                }
                else
                {
                    height = 1 + dist;
                    sum += (dist + 1);
                }
            }
            else
            {
                if (prev_candy == 1)
                {
                    sum += 2;
                }
                else
                {
                    sum++;
                }
                height_max = max(2, prev_candy);
                prev_candy = 1;
                pos_max = i - 1;
            }
        }
        else
        {
            height_max.reset();
            pos_max.reset();
            prev_candy = 1;
            sum++;
        }
    }
    return sum;
}

int main()
{
    std::vector<int> array = {1, 2, 3, 1, 0};
    std::cout << candy(array);
    return 0;
}
