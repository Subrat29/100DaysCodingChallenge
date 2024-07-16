#include <bits/stdc++.h>
using namespace std;

// sc: n
// tc: 2^n

// F(0) = 0, F(1) = 1
// F(n) = F(n - 1) + F(n - 2), for n > 1.

int fib(int n)
{
    if (n == 0 || n == 1)
        return n;

    int ans = fib(n - 1) + fib(n - 2);
    return ans;
}

int main()
{
    return 0;
}