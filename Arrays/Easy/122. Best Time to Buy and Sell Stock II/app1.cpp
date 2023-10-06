#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maxProfit(vector<int> &prices)
{
    int buy = 0;
    int sell = 0;
    int profit = 0;
    int n = prices.size()-1;
    int i = 0;

    while (i < n)
    {
        while (i < n && prices[i + 1] <= prices[i])
        {
            i++;
        }
        buy = prices[i];

        while (i < n && prices[i + 1] > prices[i])
        {
            i++;
        }
        sell = prices[i];

        profit += sell - buy;
    }
    return profit;
}

int main()
{

    return 0;
}