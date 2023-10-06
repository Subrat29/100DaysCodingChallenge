#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Given : A subarray is a contiguous part of an array.

int subarraysDivByK(vector<int> &nums, int k)
{
    int n = nums.size();
    int count = 0;

    for (int i = 0; i < n; i++)
    {
        int sum = 0;

        for (int j = i; j < n; j++)
        {
            sum = sum + nums[j];
            if (sum % k == 0)
            {
                count++;
            }
        }
    }
    return count;
}

int main()
{
    int k = 5;
    vector<int> v;
    v.push_back(4);
    v.push_back(5);
    v.push_back(0);
    v.push_back(-2);
    v.push_back(-3);
    v.push_back(1);

    cout << "ans = " << subarraysDivByK(v, k);

    return 0;
}