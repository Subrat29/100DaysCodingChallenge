#include <iostream>
#include <vector>
#include <limits.h>
#include <algorithm>
using namespace std;

// bottom to up -> 1 to x
int solve(vector<int> &num, int x)
{
    vector<int> dp(x + 1, INT_MAX);
    dp[0] = 0;

    for (int i = 1; i <= x; i++)
    {
        for (int j = 0; j < num.size(); j++)
        {
            if (i - num[j] >= 0 && dp[i - num[j]] != INT_MAX)
                dp[i] = min(dp[i], 1 + dp[i - num[j]]);
        }
    }

    if (dp[x] == INT_MAX)
        return -1;

    return dp[x];
}

int minimumElements(vector<int> &num, int x)
{
    int ans = solve(num, x);
    return ans != INT_MAX ? ans : -1;
}

int main()
{
    return 0;
}