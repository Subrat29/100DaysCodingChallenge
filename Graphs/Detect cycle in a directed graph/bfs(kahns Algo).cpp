#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

bool isCyclic(int V, vector<int> adj[])
{
    vector<int> indegree(V);
    for (int i = 0; i < V; i++)
    {
        for (auto &&neighbour : adj[i])
        {
            indegree[neighbour]++;
        }
    }

    queue<int> q;
    for (int i = 0; i < V; i++)
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
        for (auto &&neighbor : adj[frontNode])
        {
            indegree[neighbor]--;
            if (indegree[neighbor] == 0)
                q.push(neighbor);
        }
    }
    if (cnt == V)
        return false;
    else
        return true;
}

int main()
{
    return 0;
}