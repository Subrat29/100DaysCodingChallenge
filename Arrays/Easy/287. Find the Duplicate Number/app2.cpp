#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// By piegeon hole principle
// By Binary search

int findDuplicate(vector<int> &nums)
{
    int startIndex = 0;
    int endIndex = nums.size() - 1;

    while (startIndex < endIndex)
    {
        int assumeDuplicate = (startIndex + endIndex) / 2;
        int cnt = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] <= assumeDuplicate)
            {
                cnt++;
            }
        }

        if (cnt <= assumeDuplicate)
        {
            startIndex = assumeDuplicate + 1;
        }
        else
        {
            endIndex = assumeDuplicate;
        }
    }
    return startIndex;
}

int main()
{

    return 0;
}