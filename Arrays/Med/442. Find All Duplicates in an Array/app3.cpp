#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> findDuplicates(vector<int> &nums)
{
    // remember this ans vector not count in total space complexity it is only use for to store ans ans return a vector 
    vector<int> ans;

    for (int i = 0; i < nums.size(); i++)
    {
        // step1: sbse phle mark index nikal lo -1 b/c 1 to n tk hi elem h array me
        int markIndex = abs(nums[i])-1;

        // step2: markIndex wale elem me -ve sign lga do
        nums[markIndex] = - nums[markIndex];

        // step3: -ve -ve = +ve hota h, agr ye mila means duplicate presents, also store duplicate in ans
        if(nums[markIndex] > 0)
        {
            ans.push_back(markIndex+1);
        }
    }
    return ans;
}

int main()
{

    return 0;
}