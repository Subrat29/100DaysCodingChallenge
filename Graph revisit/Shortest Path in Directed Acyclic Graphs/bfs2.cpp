#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <limits.h>
using namespace std;

vector<int> shortestPathInDAG(int n, int m, vector<vector<int>> &edges)
{
    // create adj list
    vector<vector<pair<int, int>>> adj(n);
    for (auto &&edge : edges)
    {
        int u = edge[0];
        int v = edge[1];
        int w = edge[2];
        adj[u].push_back({v, w});
    }

    vector<int> distance(n, INT_MAX);
    distance[0] = 0;

    for (int i = 0; i < n; i++)
    {
        int topNode = i;
        if (distance[topNode] != INT_MAX)
        {
            for (auto &&neighbour : adj[topNode])
            {
                int anotherNode = neighbour.first;
                int weight = neighbour.second;
                if (distance[anotherNode] > distance[topNode] + weight)
                    distance[anotherNode] = distance[topNode] + weight;
            }
        }
    }

    // In codestudio, it is given that if node has no possible way to go any other node then distance should be -1;
    for (int i = 0; i < distance.size(); i++)
    {
        if (distance[i] == INT_MAX)
            distance[i] = -1;
    }
    return distance;
}

int main()
{
    return 0;
}