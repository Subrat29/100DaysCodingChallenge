#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> fourSum(vector<int> &nums, int target)
{
    sort(nums.begin(), nums.end());
    int n = nums.size();
    vector<vector<int>> ans;

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            int l = j + 1;
            int r = n - 1;
            long int remain = (long int)target - nums[i] - nums[j];  // else throw signed integer overflow

            while (l < r)
            {
                if (nums[l] + nums[r] == remain)
                {
                    ans.push_back({nums[i], nums[j], nums[l], nums[r]});
                    l++;
                    r--;

                    while (l < r && nums[l - 1] == nums[l]) // Skip duplicate nums[l]
                    {
                        l++;
                    }
                }
                else if (nums[l] + nums[r] > remain)
                {
                    r--;
                }
                else
                {
                    l++;
                }
            }
            while (j + 1 < n && nums[j] == nums[j + 1]) // Skip duplicate nums[j]
            {
                j++;
            }
        }
        while (i + 1 < n && nums[i] == nums[i + 1]) // Skip duplicate nums[i]
        {
            i++;
        }
    }
    return ans;
}

int main()
{

    return 0;
}