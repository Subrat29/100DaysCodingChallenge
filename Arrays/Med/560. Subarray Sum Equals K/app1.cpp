#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// time exceed solution
int subarraySum(vector<int> &nums, int k)
{
    int cnt = 0;
    int n = nums.size();

    for (int i = 0; i < n; i++)
    {
        int sum = nums[i];

        if (k == sum)
        {
            cnt++;
        }

        for (int j = i + 1; j < n; j++)
        {
            sum += nums[j];

            if(sum == k)
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