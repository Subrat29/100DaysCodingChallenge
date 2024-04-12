#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solve(int n)
{
    if (n == 0)
        return 1;

    if (n < 0)
        return 0;

    return solve(n - 1) + solve(n - 2);
}

int countDistinctWays(int nStairs)
{
    return solve(nStairs);
}

int main()
{
    return 0;
}