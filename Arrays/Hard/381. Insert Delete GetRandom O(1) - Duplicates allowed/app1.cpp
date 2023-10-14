#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
using namespace std;

// Time limit exceed at 62/66

int findMaxValueOfEquation(vector<vector<int>> &points, int k)
{
    int maxValue = INT_MIN;

    for (int i = 0; i < points.size() - 1; i++)
    {
        int x1 = points[i][0];
        int y1 = points[i][1];

        for (int j = i + 1; j < points.size(); j++)
        {
            int x2 = points[j][0];
            int y2 = points[j][1];

            if (abs(x1 - x2) <= k)
            {
                int value = y1 + y2 + abs(x1 - x2);
                maxValue = max(maxValue, value);
            }
        }
    }
    return maxValue;
}

int main()
{

    return 0;
}