#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int findDuplicate(vector<int> &nums)
{
    sort(nums.begin(), nums.end());
    int ans = 0;
    for (int i = 0; i + 1 < nums.size(); i++)
    {
        if (nums[i + 1] - nums[i] == 0)
        {
            ans = nums[i];
            break;
        }
    }
    return ans;
}

int main()
{

    return 0;
}