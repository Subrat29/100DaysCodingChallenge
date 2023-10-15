#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> findIndices(vector<int> &nums, int indexDifference, int valueDifference)
{
    for (int i = 0; i < nums.size(); i++)
    {
        for (int j = i; j < nums.size(); j++)
        {
            if (abs(i - j) >= indexDifference && abs(nums[i] - nums[j]) >= valueDifference)
            {
                return {i, j};
                break;
            }
        }
    }
    return {-1, -1};
}

int main()
{

    return 0;
}