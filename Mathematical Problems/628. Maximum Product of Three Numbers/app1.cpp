#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int maximumProduct(vector<int> &nums)
{
    int n = nums.size();
    sort(nums.begin(), nums.end());

    int maxProduct1 = nums[n - 1] * nums[n - 2] * nums[n - 3];
    int maxProduct2 = nums[0] * nums[1] * nums[n - 1];
    return max(maxProduct1, maxProduct2);
}

int main()
{
    // Confusion: i think that 36 is max sum but it is -36 < -18
    vector<int> v = {-6,-1,-2,-3};
    maximumProduct(v);

    return 0;
}