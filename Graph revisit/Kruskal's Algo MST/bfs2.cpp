#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

bool cmp(vector<int> &a, vector<int> &b)
{
    return a[2] < b[2];
}

void makeSet(vector<int> &parent, vector<int> &rank, int n)
{
    for (int i = 0; i < n; i++)
    {
        parent[i] = i;
        rank[i] = 0;
    }
}

int findParent(vector<int> &parent, int node)
{
    if (parent[node] == node)
        return node;

    return parent[node] = findParent(parent, parent[node]);
}

void unionSet(int u, int v, vector<int> &rank, vector<int> &parent)
{
    u = findParent(parent, u);
    v = findParent(parent, v);

    if (rank[u] > rank[v])
    {
        parent[v] = u;
    }
    else if (rank[v] > rank[u])
    {
        parent[u] = v;
    }
    else
    {
        parent[v] = u;
        rank[u]++;
    }
}

int minimumSpanningTree(vector<vector<int>> &edges, int n)
{
    vector<int> parent(n);
    vector<int> rank(n);
    makeSet(parent, rank, n);

    sort(edges.begin(), edges.end(), cmp);

    int minWeight = 0;
    int edgesAdded = 0;

    for (auto &&edge : edges)
    {
        int u = edge[0];
        int v = edge[1];
        int w = edge[2];

        if (findParent(parent, u) != findParent(parent, v))
        {
            unionSet(u, v, rank, parent);
            minWeight += w;
            edgesAdded++;

            if (edgesAdded == n - 1) // Stop when n-1 edges are added
                break;
        }
    }

    return minWeight;
}
