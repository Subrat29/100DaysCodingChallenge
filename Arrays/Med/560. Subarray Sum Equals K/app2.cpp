#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

int subarraySum(vector<int> &nums, int k)
{
    int n = nums.size();

    // make a prefix array to store prefix sum
    int prefix[n];

    prefix[0] = nums[0];
    for (int i = 1; i < n; i++)
    {
        prefix[i] = nums[i] + prefix[i - 1];
    }

    int ans = 0;
    unordered_map<int, int> m;

    for (int i = 0; i < n; i++)
    {
        if (prefix[i] == k)
        {
            ans++;
        }

        if (m.find(prefix[i] - k) != m.end())
        {
            ans = ans + m[prefix[i] - k];
        }

        m[prefix[i]]++;
    }
    return ans;
}

int main()
{

    return 0;
}