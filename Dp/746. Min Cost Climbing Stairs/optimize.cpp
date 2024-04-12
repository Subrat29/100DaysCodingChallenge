#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int minCostClimbingStairs(vector<int> &cost)
{
    int x = 0;
    int y = cost[cost.size() - 1];

    for (int i = cost.size() - 2; i >= 0; i--)
    {
        int temp = y;
        y = min(y, x) + cost[i];
        x = temp;
    }
    return min(y, x);
}

int main()
{
    return 0;
}