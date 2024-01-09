#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int time = 0;
void dfs(int src, int parent, vector<int> &vis, vector<int> adj[], vector<int> &tin, vector<int> &low, vector<vector<int>> &ans)
{
    vis[src] = 1;
    tin[src] = time;
    low[src] = time;
    time++;
    for (auto it : adj[src])
    {

        if (it == parent)
            continue;

        if (!vis[it])
        {

            dfs(it, src, vis, adj, tin, low, ans);
            low[src] = min(low[src], low[it]);

            if (low[it] > tin[src])
            {
                ans.push_back({it, src});
            }
        }
        else
        {
            low[src] = min(low[src], low[it]);
        }
    }
}

vector<vector<int>> criticalConnections(int n, vector<vector<int>> &con)
{
    vector<int> adj[n];

    for (int i = 0; i < con.size(); i++)
    {
        adj[con[i][0]].push_back(con[i][1]);
        adj[con[i][1]].push_back(con[i][0]);
    }
    vector<vector<int>> ans;
    vector<int> vis(n, 0);
    vector<int> tin(n);
    vector<int> low(n);

    dfs(0, 0, vis, adj, tin, low, ans);

    return ans;
}

int main()
{
    return 0;
}