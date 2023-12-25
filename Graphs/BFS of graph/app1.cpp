#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

vector<int> bfsOfGraph(int V, vector<int> adj[])
{
    vector<bool> vis(V, false);
    int s = 0;
    vis[s] = true;

    vector<int> res;
    queue<int> q;
    q.push(s);

    while (!q.empty())
    {
        int t = q.front();
        res.push_back(t);
        q.pop();

        for (int v : adj[t])
        {
            if (!vis[v])
            {
                vis[v] = true;
                q.push(v);
            }
        }
    }
    return res;
}

int main()
{
    return 0;
}
