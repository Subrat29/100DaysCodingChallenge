#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

// source pepcoding: https://www.youtube.com/watch?v=QM0klnvTQzk

int subarraysDivByK(vector<int> &nums, int k)
{
    unordered_map<int, int> remFrequency;
    remFrequency[0] = 1;

    int sum = 0;
    int rem = 0;
    int ans = 0;

    for(int i=0; i<nums.size(); i++)
    {
        sum += nums[i];
        rem = sum % k;

        // if rem is negative then add k eg. -1 = (-1+5) = 4 
        if(rem < 0)
        {
            rem += k;
        }

        if(remFrequency.find(rem) != remFrequency.end())
        {
            ans += remFrequency[rem];
        }
        remFrequency[rem]++;
    }
    return ans;
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

    cout << "ans = " << subarraysDivByK(v,k);
    
    return 0;
}