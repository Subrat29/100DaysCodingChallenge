#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
using namespace std;

int findPeakElement(vector<int> &nums)
{
    pair<int, int> peak = {INT_MIN, 0};
    for (int i = 0; i < nums.size(); i++)
    {
        if (peak.first < nums[i])
        {
            peak.first = nums[i];
            peak.second = i;
        }
    }
    return peak.second;
}

int main()
{

    return 0;
}