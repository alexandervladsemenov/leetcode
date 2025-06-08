#include "common.h"
constexpr int N = 1001;
std::array<int, N> counts;
int hIndex(vector<int> &citations)
{

    for (const auto &c : citations)
    {
        counts[c]++;
    }
    int h = 0;
    for (int i = N - 1; i > 0; i--)
    {
        if (counts[i])
        {
            if(h < i)
            {
                h += counts[i];
                if (h > i)
                {
                    h = i;
                    break;
                }
            }
            else
                break;
        }
    }
    return h;
}

int main()
{
    std::vector<int> inp = {3, 0, 6, 1, 5};
    std::cout << hIndex(inp) << "\n";
    return 0;
}