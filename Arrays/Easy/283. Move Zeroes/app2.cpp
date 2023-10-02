#include <iostream>
#include <vector>
using namespace std;

// snowBall Approach
void moveZeroes(vector<int> &nums)
{
    int snowSize = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if(nums[i] == 0)
        {
            snowSize++;
        }
        else if(snowSize > 0)
        {
            int temp = nums[i];
            nums[i] = 0;
            nums[i-snowSize] = temp;
        }
    }
}

int main()
{

    return 0;
}