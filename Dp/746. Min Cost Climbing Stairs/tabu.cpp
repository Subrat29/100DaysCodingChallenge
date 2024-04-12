#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int minCostClimbingStairs(vector<int> &cost)
{
    vector<int> dp(cost.size() + 1, -1);
    dp[cost.size()] = 0;
    dp[cost.size() - 1] = cost[cost.size() - 1];

    for (int i = cost.size() - 2; i >= 0; i--)
    {
        dp[i] = min(dp[i + 1], dp[i + 2]) + cost[i];
    }
    return min(dp[0], dp[1]);
}

int main()
{
    return 0;
}