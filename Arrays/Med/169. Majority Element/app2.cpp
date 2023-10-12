#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Time complexity = O(n)
// Space complexity = O(1)

// ok, got it. it's trick. An assumption is the frequency of majority element > n/2

int majorityElement(vector<int> &nums)
{
    int cnt = 1;
    int maj = nums[0];

    for (int i = 1; i < nums.size(); i++)
    {
        if (cnt == 0)
        {
            cnt++;
            maj = nums[i];
        }
        else if (maj == nums[i])
        {
            cnt++;
        }
        else
        {
            cnt--;
        }
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