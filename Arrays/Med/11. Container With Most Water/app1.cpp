#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Time Limit Exceeded
int maxArea(vector<int> &height)
{
    int n = height.size();
    int maxArea = 0;

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            int l = min(height[i], height[j]);
            int b = j - i;
            int area = l * b;
            maxArea = max(maxArea, area);
        }
    }
    return maxArea;
}

int main()
{

    return 0;
}