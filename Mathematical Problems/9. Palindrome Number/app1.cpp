#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool isPalindrome(int x)
{
    string nums = to_string(x);
    int i = 0;
    int j = nums.size() - 1;
    while (i <= j)
    {
        if (nums[i++] != nums[j--])
        {
            return false;
        }
    }
    return true;
}

int main()
{
    cout << isPalindrome(11211);
    return 0;
}