#include <iostream>
#include <vector>
#include <limits.h>
#include <algorithm>
using namespace std;

int solve(vector<int> &num, int x)
{
    if (x == 0)
        return 0;
    if (x < 0)
        return INT_MAX;

    int minElem = INT_MAX;
    for (int i = 0; i < num.size(); i++)
    {
        if (solve(num, x-num[i]) != INT_MAX)
            minElem = min(minElem, solve(num, x - num[i]) + 1);
    }
    return minElem;
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