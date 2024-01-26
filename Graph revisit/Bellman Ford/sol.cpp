#include <iostream>
#include <vector>
#include <limits.h>
#include <algorithm>
using namespace std;

vector<int> bellmonFord(int n, int m, int src, vector<vector<int>> &edges)
{
    // adj list
    vector<vector<pair<int, int>>> adj(n + 1);
    for (auto &&edge : edges)
    {
        int u = edge[0];
        int v = edge[1];
        int w = edge[2];
        adj[u].push_back({v, w});
    }

    // distance vector
    vector<int> distance(n + 1, 100000000);
    distance[src] = 0;

    // run n-1 times to find shortest path from src
    for (int i = 1; i < n; i++)
    {
        for (int node = 1; node <= n; node++)
        {
            for (auto &&neighbour : adj[node])
            {
                int anotherNode = neighbour.first;
                int weight = neighbour.second;

                if (distance[node] + weight < distance[anotherNode])
                    distance[anotherNode] = distance[node] + weight;
            }
        }
    }

    // check cycle present or not
    // int isCyclePresent = false;
    // for (int node = 1; node <= n; node++)
    // {
    //     for (auto &&neighbour : adj[node])
    //     {
    //         int anotherNode = neighbour.first;
    //         int weight = neighbour.second;

    //         if (distance[node] + weight < distance[anotherNode])
    //             isCyclePresent = true;
    //     }
    // }
    // if (isCyclePresent == false)
    return distance;
}

int main()
{
    return 0;
}