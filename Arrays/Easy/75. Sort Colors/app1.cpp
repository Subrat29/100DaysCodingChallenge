#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void sortColors(vector<int> &nums)
{
    int cnt_0s = 0;
    int cnt_1s = 0;
    int cnt_2s = 0;

    while (nums.size())
    {
        if (nums[nums.size()] == 0)
        {
            cnt_0s++;
            nums.pop_back();
        }
        else if (nums[nums.size()] == 1)
        {
            cnt_1s++;
            nums.pop_back();
        }
        else
        {
            cnt_2s++;
            nums.pop_back();
        }
    }

    while (cnt_0s)
    {
        nums.push_back(0);
    }

    while (cnt_1s)
    {
        nums.push_back(1);
    }

    while (cnt_2s)
    {
        nums.push_back(2);
    }
}

int main()
{

    return 0;
}