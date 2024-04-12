#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solve(vector<int> &cost, int n)
{
    if (n >= cost.size())
        return 0;

    return min(solve(cost, n + 1), solve(cost, n + 2)) + cost[n];
}

int minCostClimbingStairs(vector<int> &cost)
{
    return min(solve(cost, 0), solve(cost, 1));
}

int main()
{
    return 0;
}