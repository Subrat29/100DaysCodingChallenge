#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int fibo(int n, vector<int> &dp)
{
    // base case
    if (n <= 1)
        return n;

    // if dp[n] is already calculated then no need to further calling
    if (dp[n] != -1)
        return dp[n];

    dp[n] = fibo(n - 1, dp) + fibo(n - 2, dp);
    return dp[n];
}

int main()
{
    int n;
    cin >> n;
    vector<int> dp(n + 1, -1);
    cout << fibo(n, dp);
    return 0;
}