#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Time complexity = O(n^2) 
// Space complexity = O(1)

int majorityElement(vector<int> &nums)
{
    sort(nums.begin(), nums.end());
    int maj = 0;
    int cnt = 0;
    int i = 0;
    int n = nums.size();

    if (n == 1)
    {
        return nums[0];
    }

    while (i < n - 1)
    {
        int temp = 0;
        while (i < n - 1 && nums[i] == nums[i + 1])
        {
            temp++;
            i++;
        }
        if (temp >= n / 2 && temp > cnt)
        {
            maj = nums[i - 1];
            cnt = temp;
        }
        i++;
    }
    return maj;
}

int main()
{
    vector<int> v;
    v.push_back(1);

    int ans = majorityElement(v);
    cout << ans << endl;

    return 0;
}