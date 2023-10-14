#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <limits.h>
using namespace std;

int findMaxValueOfEquation(vector<vector<int>> &points, int k)
{
    // maxHeap
    priority_queue<pair<int, int>> q;
    q.push({points[0][1] - points[0][0], points[0][0]});
    int maxValue = INT_MIN;

    for (int i = 1; i < points.size(); i++)
    {
        int sum = points[i][1] + points[i][0];
        while (!q.empty() && points[i][0] - q.top().second > k)
        {
            q.pop();
        }
        if (!q.empty())
        {
            maxValue = max(maxValue, q.top().first + sum);
        }
        q.push({points[i][1] - points[i][0], points[i][0]});
    }
    return maxValue;
}

int main()
{

    return 0;
}