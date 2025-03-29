#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>
using namespace std;

vector<int> dijkstra(vector<vector<int>> &vec, int n, int edges, int source)
{
    // Create adjacency list
    vector<vector<pair<int, int>>> adj(n);
    for (auto &&edge : vec)
    {
        int u = edge[0];
        int v = edge[1];
        int w = edge[2];
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    // Min-heap (Dijkstra's priority queue) -> (distance, node)
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    vector<int> dist(n, INT_MAX);

    // Start from source
    q.push({0, source});
    dist[source] = 0;

    while (!q.empty())
    {
        int currentDist = q.top().first;
        int frontNode = q.top().second;
        q.pop();

        // Ignore outdated distance values
        if (currentDist > dist[frontNode])
            continue;

        for (auto &&neighbour : adj[frontNode])
        {
            int anotherNode = neighbour.first;
            int anotherNodeWt = neighbour.second;

            if (dist[anotherNode] > dist[frontNode] + anotherNodeWt)
            {
                dist[anotherNode] = dist[frontNode] + anotherNodeWt;
                q.push({dist[anotherNode], anotherNode});
            }
        }
    }
    return dist;
}

int main()
{
    return 0;
}
