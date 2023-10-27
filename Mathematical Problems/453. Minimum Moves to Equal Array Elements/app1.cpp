#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
using namespace std;

int minMoves(vector<int> &nums)
{
    int minElem = INT_MAX;
    for (int i = 0; i < nums.size(); i++)
    {
        minElem = min(nums[i], minElem);
    }

    int ans = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        ans += nums[i] - minElem;
    }
    return ans;
}

int main()
{

    return 0;
}