#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int missingNumber(vector<int> &nums)
{
    int n = nums.size();
    int totalSum = (n * (n + 1)) / 2;

    int sum = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        sum += nums[i];
    }
    return totalSum - sum;
}

int main()
{

    return 0;
}