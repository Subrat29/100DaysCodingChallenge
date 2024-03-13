#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int dfs(int idx, vector<bool> &visited, vector<vector<int>> &stones)
{
    visited[idx] = true;
    int result = 0;
    for (int i = 0; i < stones.size(); i++)
    {
        if (!visited[i] && (stones[i][0] == stones[idx][0] || stones[i][1] == stones[idx][1]))
            result += dfs(i, visited, stones) + 1;
    }
    return result;
}

int removeStones(vector<vector<int>> &stones)
{
    int n = stones.size();
    vector<bool> visited(n, false);

    int result = 0;
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
            result += dfs(i, visited, stones);

        cout << result << endl;
    }
    return result;
}

int main()
{
    vector<vector<int>> stones = {{0, 1}, {0, 2}, {4, 3}, {2, 4}, {0, 3}, {1, 1}};
    cout << "Ans: " << removeStones(stones);
    return 0;
}