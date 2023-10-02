#include <iostream>
#include <vector>
using namespace std;

void moveZeroes(vector<int> &nums)
{
    vector<int> v;
    int cnt = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] != 0)
        {
            v.push_back(nums[i]);
        }
        else
        {
            cnt++;
        }
    }
    while (cnt)
    {
        v.push_back(0);
    }

    nums = v;
}

int main()
{

    return 0;
}

// 0,1,0,3,12,0