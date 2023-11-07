#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Time Limit Exceeded
vector<long long int> productExceptSelf(vector<long long int> &nums, int n)
{
    vector<long long int> ans(n, 1); // Initialize the answer vector with 1s.

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (j != i)
            {
                ans[i] *= nums[j];
            }
        }
    }
    return ans;
}

int main()
{

    return 0;
}