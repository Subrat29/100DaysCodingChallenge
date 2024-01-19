#include <iostream>
#include <vector>
#include <limits.h>
#include <algorithm>
using namespace std;

vector<pair<pair<int, int>, int>> calculatePrimsMST(int n, int m, vector<pair<pair<int, int>, int>> &g)
{
    // adj list
    vector<vector<pair<int, int>>> adj(n + 1);
    for (auto &&edge : g)
    {
        int u = edge.first.first;
        int v = edge.first.second;
        int w = edge.second;

        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    // distance vector
    vector<int> dis(n + 1, INT_MAX);

    // mst vector
    vector<bool> mst(n + 1, false);

    // parent vector
    vector<int> parent(n + 1, -1);

    dis[1] = 0;
    for (int j = 1; j < n; j++)
    {
        int mini = INT_MAX;
        int u;
        for (int i = 1; i <= n; i++)
        {
            if (mst[i] == false && dis[i] < mini)
            {
                mini = dis[i];
                u = i;
            }
        }

        mst[u] = true;
        for (auto &&neighbour : adj[u])
        {
            int v = neighbour.first;
            int wt = neighbour.second;

            if (mst[v] == false && dis[v] > wt) // (dis[u] + wt) not do this because end me wt lotana h
            {
                dis[v] = wt;
                parent[v] = u;
            }
        }
    }

    // return result
    vector<pair<pair<int, int>, int>> res;
    for (int i = 2; i <= n; i++)
    {
        res.push_back({{i, parent[i]}, dis[i]});
        //     res[i].push_back({i, parent[i]});
        //     res[i].second.push_back(dis[i]);
        //     res[i] = {{i, parent[i]}, dis[i]};   (because res[i] is not a container)
    }
    return res;
}

int main()
{
    return 0;
}