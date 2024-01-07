#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
using namespace std;

int isNegativeWeightCycle(int n, vector<vector<int>> edges)
{
    // Code here
    vector<int> dist(n, 1e8);
    dist[0] = 0;
    for (int j = 0; j < n - 1; j++)
    {
        for (auto &&edge : edges)
        {
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];

            if (dist[u] + wt < dist[v])
                dist[v] = dist[u] + wt;
        }
    }
    for (auto &&edge : edges)
    {
        int u = edge[0];
        int v = edge[1];
        int wt = edge[2];

        if (dist[u] + wt < dist[v])
            return 1;
    }
    return 0;
}

int main()
{
    return 0;
}