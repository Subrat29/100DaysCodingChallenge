#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maxProfit(vector<int> &prices)
{
    int maxProfit = 0;
    for (int i = 0; i < prices.size(); i++)
    {
        for (int j = i+1; j < prices.size(); j++)
        {
            int profit = prices[j] - prices[i];
            maxProfit = max(maxProfit, profit);
        }   
    }
    return maxProfit;
}

int main()
{

    return 0;
}