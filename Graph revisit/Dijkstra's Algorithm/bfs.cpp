#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <limits.h>
using namespace std;

vector<int> dijkstra(vector<vector<int>> &vec, int n, int edges, int source)
{
    // create adj list
    vector<vector<pair<int, int>>> adj(n);
    for (auto &&edge : vec)
    {
        int u = edge[0];
        int v = edge[1];
        int w = edge[2];
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    // create a set which return the lowest distance node always - <distance,node> (reason at last loc)
    priority_queue<pair<int, int>> q;
    vector<int> dist(n, INT_MAX);

    q.push({0, source});
    dist[source] = 0;

    while (!q.empty())
    {
        int frontNode = q.top().second;
        q.pop();

        for (auto &&neighbour : adj[frontNode])
        {
            int anotherNode = neighbour.first;
            int anotherNodeWt = neighbour.second;
            if (dist[anotherNode] > dist[frontNode] + anotherNodeWt)
            {
                dist[anotherNode] = dist[frontNode] + anotherNodeWt;
                q.push({anotherNodeWt, anotherNode});
            }
        }
    }
    return dist;
}

// SET PROPERTY:
// the sorting is done lexicographically. This means that the first element of the pair is the primary key
// for sorting, and if two pairs have the same first element, then the second element is used for further
// comparison.

int main()
{
    return 0;
}