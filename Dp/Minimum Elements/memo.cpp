#include <iostream>
#include <vector>
#include <limits.h>
#include <algorithm>
using namespace std;

int solve(vector<int> &num, int x, vector<int> &dp)
{
    if (x == 0)
        return 0;
    if (x < 0)
        return INT_MAX;

    if (dp[x] != -1)
        return dp[x];

    int minElem = INT_MAX;
    for (int i = 0; i < num.size(); i++)
    {
        int ans = solve(num, x - num[i], dp);
        if (ans != INT_MAX)
        {
            minElem = min(minElem, ans + 1);
        }
    }
    dp[x] = minElem;
    return minElem;
}

int minimumElements(vector<int> &num, int x)
{
    vector<int> dp(x + 1, -1);
    int ans = solve(num, x, dp);

    return ans != INT_MAX ? ans : -1;
}

int main()
{
    return 0;
}