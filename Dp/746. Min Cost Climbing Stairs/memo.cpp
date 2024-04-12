#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solve(vector<int> &cost, int n, vector<int> &dp)
{
    if (n >= cost.size())
        return 0;
    if (dp[n] != -1)
        return dp[n];
    dp[n] = min(solve(cost, n + 1, dp), solve(cost, n + 2, dp)) + cost[n];
    return dp[n];
}

int minCostClimbingStairs(vector<int> &cost)
{
    vector<int> dp(cost.size() + 1, -1);
    return min(solve(cost, 0, dp), solve(cost, 1, dp));
}

int main()
{
    return 0;
}