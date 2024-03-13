#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int removeStones(vector<vector<int>> &stones)
{
    sort(stones.begin(), stones.end(), [](vector<int> &a, vector<int> &b)
         {
    if (a[0] == b[0])
        return a[1] < b[1];
    return a[0] < b[0]; });

    int cnt = 0;
    for (int i = 0; i < stones.size(); i++)
    {
        int x1 = stones[i][0];
        int y1 = stones[i][1];

        for (int j = i + 1; j < stones.size(); j++)
        {
            int x2 = stones[j][0];
            int y2 = stones[j][1];
            if (x1 == x2 || y1 == y2)
            {
                cnt++;
                break;
            }
        }
    }
    return cnt;
}

int main()
{
    return 0;
}