#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int splitArray(vector<int> &nums, int k)
{
    int l = 0;
    int r = 0;
    int n = nums.size();

    for (int i = 0; i < n; i++)
    {
        l = max(l, nums[i]);
        r += nums[i];
    }

    int mid = 0;
    int ans = 0;
    while (l <= r)
    {
        mid = (l + r) / 2;
        int count = 0;
        int tempSum = 0;
        for (int i = 0; i < n; i++)
        {
            if (tempSum + nums[i] <= mid)
            {
                tempSum += nums[i];
            }
            else
            {
                count++;
                tempSum = nums[i];
            }
        }
        count++;

        if (count <= k)
        {
            r = mid - 1;
            ans = mid;
        }
        else
        {
            l = mid + 1;
        }
    }
    return ans;
}

int main()
{
    return 0;
}
