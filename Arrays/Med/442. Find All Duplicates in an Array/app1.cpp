#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Time limit exceed...oops
vector<int> findDuplicates(vector<int> &nums)
{
    sort(nums.begin(), nums.end());
    int n = nums.size()-1;

    for (int i = 0; i < n; i++)
    {
        if (nums[0] == nums[1])
        {
            nums.push_back(nums[0]);
        }
        nums.erase(nums.begin());
    }
    nums.erase(nums.begin());
    return nums;
}

int main()
{

    // vector<int> v = {4,3,2,7,8,2,3,1};
    vector<int> v = {1,2,3,5,2};

    vector<int> ans = findDuplicates(v);

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }

    return 0;
}