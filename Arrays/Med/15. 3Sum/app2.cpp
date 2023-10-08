#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> threeSum(vector<int> &nums)
{
    int n = nums.size();

    vector<vector<int>> ans;

    // sort the array
    sort(nums.begin(), nums.end());

    // convert ques like 2 sum ques
    // x + y + z = 0   => x + y = -z

    for (int i = 0; i < n; i++)
    {
        int target = -nums[i];
        int front = i + 1;
        int end = n - 1;

        while (front < end)
        {
            int sum = nums[front] + nums[end];

            if (sum < target)
            {
                front++;
            }
            else if (sum > target)
            {
                end--;
            }
            else
            {
                vector<int> triplet = {nums[i], nums[front], nums[end]};
                ans.push_back(triplet);

                // check duplicate elements present in nums for front
                while (front < end && nums[front] == triplet[1])
                {
                    front++;
                }

                // check duplicate elements present in nums for back
                while (front < end && nums[end] == triplet[2])
                {
                    end--;
                }
            }
        }

        // check duplicate elements present in nums for num[i]
        while (i+1 < n && nums[i + 1] == nums[i])
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