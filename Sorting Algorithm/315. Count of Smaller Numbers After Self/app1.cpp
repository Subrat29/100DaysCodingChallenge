#include <iostream>
#include <vector>
using namespace std;

// tle maring
vector<int> countSmaller(vector<int> &nums)
{
    vector<int> ans;
    int n = nums.size();
    for (int i = 0; i < n; i++)
    {
        int cnt = 0;
        for (int j = i + 1; j < n; j++)
        {
            if (nums[j] < nums[i])
                cnt++;
        }
        ans.push_back(cnt);
    }
    return ans;
}

int main()
{
    return 0;
}
