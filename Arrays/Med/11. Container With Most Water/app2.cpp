#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maxArea(vector<int> &height)
{
    int i = 0;
    int j = height.size()-1;
    int maxArea = 0;

    while (i<j)
    {
        int l = min(height[i], height[j]);
        int b = j-i;
        int area = l*b;

        maxArea = max(maxArea, area);

        if(height[i] <= height[j])
        {
            i++;
        }
        else
        {
            j--;
        }
    }
    return maxArea;
}

int main()
{
    cout<< max(4,4);

    return 0;
}