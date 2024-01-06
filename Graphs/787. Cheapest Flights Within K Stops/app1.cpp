#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
using namespace std;

int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst, int k)
{
    vector<int> dist(n, INT_MAX);
    dist[src] = 0;

    for (int l = 0; l <= k; ++l)
    {
        vector<int> temp(dist);
        for (const auto &f : flights)
        {
            int u = f[0], v = f[1], w = f[2];
            if (dist[u] != INT_MAX)
            {
                temp[v] = min(temp[v], dist[u] + w);
            }
        }

        dist = temp;
    }

    return dist[dst] == INT_MAX ? -1 : dist[dst];
}

int main()
{
    return 0;
}