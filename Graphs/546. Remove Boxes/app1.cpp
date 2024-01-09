#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int recur(vector<int> &arr, int l, int r, int k, vector<vector<vector<int>>> &dp)
{
    if (l > r)
    {
        return 0;
    }

    if (dp[l][r][k] != -1)
    {
        return dp[l][r][k];
    }

    int idx = l, cnt = 0;
    while (idx + 1 <= r && arr[idx] == arr[idx + 1])
    {
        cnt++;
        idx++;
    }
    cnt++;
    int ans = ((k + cnt) * (k + cnt)) + recur(arr, idx + 1, r, 0, dp);
    for (int i = idx + 1; i <= r; i++)
    {
        if (arr[idx] == arr[i])
        {
            int temp = recur(arr, idx + 1, i - 1, 0, dp) + recur(arr, i, r, (k + cnt), dp);
            ans = max(ans, temp);
        }
    }
    return dp[l][r][k] = ans;
}

int removeBoxes(vector<int> &boxes)
{
    int n = boxes.size();
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(n, -1)));
    return recur(boxes, 0, boxes.size() - 1, 0, dp);
}

int main()
{
    return 0;
}