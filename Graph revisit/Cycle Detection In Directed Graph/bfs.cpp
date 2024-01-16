#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

// by kahn's algo (bfs)

int detectCycleInDirectedGraph(int n, vector<pair<int, int>> &edges)
{
    vector<vector<int>> adj(n + 1);
    vector<int> indegree(n + 1, 0);
    for (auto &&edge : edges)
    {
        int u = edge.first;
        int v = edge.second;
        adj[u].push_back(v);

        indegree[v]++;
    }

    queue<int> q;
    for (int i = 1; i <= n; i++)
    {
        if (indegree[i] == 0)
            q.push(i);
    }

    int cnt = 0;
    while (!q.empty())
    {
        int frontNode = q.front();
        q.pop();

        cnt++;
        for (auto &&neighbour : adj[frontNode])
        {
            indegree[neighbour]--;
            if (indegree[neighbour] == 0)
                q.push(neighbour);
        }
    }
    if (cnt == n)
        return false;
    else
        return true;
}

int main()
{
    return 0;
}