#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

// by kahn's algorithm (bfs)

vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)
{
    // adjacency and indegree vector
    vector<vector<int>> adj(v);
    vector<int> indegree(v, 0);
    vector<int> topo;

    for (auto &&edge : edges)
    {
        int u = edge[0];
        int v = edge[1];
        adj[u].push_back(v);
        indegree[v]++;
    }

    /*
    You are correct in your understanding of Kahn's algorithm. The reason for pushing nodes with indegree 0
    into the queue is to identify the source nodes, which can be considered as starting points for
    the topological sort.
    */

    queue<int> q;
    for (int i = 0; i < v; i++)
    {
        if (indegree[i] == 0)
            q.push(i);
    }

    while (!q.empty())
    {
        int frontNode = q.front();
        q.pop();
        topo.push_back(frontNode);

        for (auto &&neighbour : adj[frontNode])
        {
            indegree[neighbour]--;
            if (indegree[neighbour] == 0)
                q.push(neighbour);
        }
    }
    return topo;
}

int main()
{
    return 0;
}