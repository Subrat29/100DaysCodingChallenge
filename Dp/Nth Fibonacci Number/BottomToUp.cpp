#include <bits/stdc++.h>
using namespace std;

// sc: n
// tc: n

// F(0) = 0, F(1) = 1
// F(n) = F(n - 1) + F(n - 2), for n > 1.

// Approach: Bottom to up

// step1
vector<int> dp(31, -1);

int fib(int n)
{
    // step2
    dp[0] = 0;
    dp[1] = 1;

    // step3
    for (int i = 2; i <= n; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n];
}

int main()
{
    int n = 8;
    int ans = fib(n);
    cout << "Fibo: " << ans;
    return 0;
}