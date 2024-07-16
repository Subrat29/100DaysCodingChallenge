#include <bits/stdc++.h>
using namespace std;

// sc: n + n = n
// tc: n (because no overlaping subproblem traverse every node exactly one time)

// F(0) = 0, F(1) = 1
// F(n) = F(n - 1) + F(n - 2), for n > 1.

// Note: Why dp array of n+1?
// Ans: Because we the fibo series is starting from 0 therefore if we create a 5 size array then we know that it creates from 0 to 4 so
// for including the 5 also we take n+1 instead of n.

// step1
vector<int> dp(31, -1);

int fib(int n)
{
    if (n == 0 || n == 1)
        return n;

    // step3
    if (dp[n] != -1)
        return dp[n];

    // step2
    dp[n] = fib(n - 1) + fib(n - 2);
    return dp[n];
}

int main()
{
    int n = 8;
    int ans = fib(n);
    cout << "Fibo: " << ans;
    return 0;
}