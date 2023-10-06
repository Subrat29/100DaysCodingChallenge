#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int removeDuplicates(vector<int> &nums)
{
    for (int i=0; i<nums.size()-1; i++)
    {
        if(nums[i] == nums[i+1])
        {
            nums.erase(nums.begin()+i);
            i--;
        }
    }
    return nums.size(); 
}

int main()
{
    vector<int>v;
    v.push_back(1);
    v.push_back(1);
    v.push_back(2);

    cout << removeDuplicates(v) << endl;

    for (auto &&i : v)
    {
        cout << i << " ";
    }
    return 0;
}