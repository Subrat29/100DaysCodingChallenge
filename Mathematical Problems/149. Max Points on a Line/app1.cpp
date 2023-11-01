#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <math.h>
using namespace std;

int maxPoints(vector<vector<int>> &points)
{
    int ans = 0; // c
    int n = points.size();

    for (int i = 0; i < n - 1; i++)
    {
        map<double, int> mp;
        for (int j = i + 1; j < n; j++)
        {
            // slope = y2-y1 / x2-x1
            double x = (double)(points[j][1] - points[i][1]) / (double)(points[j][0] - points[i][0]);

            // infinite slop for Perpendicular line
            if (points[j][1] - points[i][1] < 0 && (points[j][0] - points[i][0]) == 0)
            {
                mp[abs(x)]++;
            }
            else
            {
                mp[x]++;
            }
        }

        int temp = 0;
        for (auto &&i : mp)
        {
            temp = max(temp, i.second + 1); // +1 to include current point
        }
        ans = max(ans, temp);
    }
    return ans;
}

int main()
{

    return 0;
}