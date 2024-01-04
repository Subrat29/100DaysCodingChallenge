#include <iostream>
#include <vector>
#include <limits.h>
#include <algorithm>
using namespace std;

int spanningTree(int V, vector<vector<int>> adj[])
{
    // code here
    vector<int> key(V, INT_MAX);
    vector<int> parent(V, -1);
    vector<bool> mst(V, false);

    parent[0] = -1;
    key[0] = 0;

    for (int i = 1; i < V; i++)
    {
        int u;
        int m = INT_MAX;
        for (int j = 0; j < V; j++)
        {
            if (!mst[j] && m > key[j])
            {
                u = j;
                m = key[j];
            }
        }

        mst[u] = true;

        for (auto nei : adj[u])
        {
            int v = nei[0];
            int w = nei[1];

            if (!mst[v] && key[v] > w)
            {
                key[v] = w;
                parent[v] = u;
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < V; i++)
    {
        ans += key[i];
    }
    return ans;
}

int main()
{
    return 0;
}