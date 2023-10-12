#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// time complexity : O(n^2)
int reversePairs(vector<int> &nums)
{
    int cnt = 0;
    for (int i = 0; i < nums.size()-1; i++)
    {
        for (int j = i + 1; j < nums.size() - 1; j++)
        {
            if ((long long)nums[i] > 2 * (long long)nums[j])
            {
                cnt++;
            }
        }
    }
    return cnt;
}

int main()
{

    return 0;
}