#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

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

    if (rank[u] >= rank[v])
    {
        parent[v] = u;
        rank[u]++;
    }
    else
    {
        parent[u] = v;
        rank[v]++;
    }
}

int minimumSpanningTree(vector<vector<int>> &edges, int n)
{
    vector<int> parent(n);
    vector<int> rank(n);
    makeSet(parent, rank, n);

    priority_queue<
        pair<int, pair<int, int>>,              // Element type
        vector<pair<int, pair<int, int>>>,      // Container type
        std::greater<pair<int, pair<int, int>>> // Comparison function (min heap in this case) (*Note* std:: is needed as error comes)
        >q;

    for (auto &&edge : edges)
    {
        int u = edge[0];
        int v = edge[1];
        int w = edge[2];
        q.push({w, {u, v}});
    }

    int minWeight = 0;
    int edgesAdded = 0; // *Important to remove TLE
    while (!q.empty())
    {
        int u = q.top().second.first;
        int v = q.top().second.second;
        int w = q.top().first;
        q.pop();

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

int main()
{
    return 0;
}