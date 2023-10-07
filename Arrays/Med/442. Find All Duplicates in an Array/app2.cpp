#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> findDuplicates(vector<int> &nums)
{
    sort(nums.begin(), nums.end());
    vector<int> ans;
    int n = nums.size() - 1;

    for (int i = 0; i < n; i++)
    {
        if (nums[i] == nums[i + 1])
        {
            ans.push_back(nums[i]);
        }
    }
    return ans;
}

int main()
{

    return 0;
}