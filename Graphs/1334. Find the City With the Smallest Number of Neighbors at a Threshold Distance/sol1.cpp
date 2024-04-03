#include <iostream>
#include <vector>
#include <limits.h>
#include <algorithm>
using namespace std;

void dfs(int node, vector<int> &visited, vector<vector<int>> &edges, vector<vector<pair<int, int>>> &adj, int &maxDist, int &dist, int &city)
{
    visited[node] = true;
    for (auto &&nbr : adj[node])
    {
        if (!visited[nbr.first] && dist + nbr.second <= maxDist)
        {
            dist += nbr.second;
            city++;
            dfs(nbr.first, visited, edges, adj, maxDist, dist, city);
            dist -= nbr.second;
        }
    }
    visited[node] = false;
}

int findTheCity(int n, vector<vector<int>> &edges, int distanceThreshold)
{
    vector<vector<pair<int, int>>> adj(n);
    for (auto &&edge : edges)
    {
        int u = edge[0];
        int v = edge[1];
        int wt = edge[2];
        adj[u].push_back({v, wt});
        adj[v].push_back({u, wt});
    }

    for (int i = 0; i < n; i++)
    {
        cout << i << ": ";
        for (auto &&j : adj[i])
        {
            cout << "( " << j.first << ", " << j.second << " )";
        }
        cout << endl;
    }

    vector<int> noOfCity(n, 0);
    for (int i = 0; i < n; i++)
    {
        vector<int> visited(n, 0);
        int dist = 0, city = 0;
        dfs(i, visited, edges, adj, distanceThreshold, dist, city);
        noOfCity[i] = city;
    }

    for (int i = 0; i < noOfCity.size(); i++)
    {
        cout << i << ": " << noOfCity[i] << endl;
    }

    int mini = INT_MAX;
    int ans = 0;
    for (int i = 0; i < noOfCity.size(); i++)
    {
        if (mini > noOfCity[i])
        {
            mini = noOfCity[i];
            ans = i;
        }
        else if (mini == noOfCity[i])
        {
            ans = max(ans, i);
        }
    }
    return ans;
}

int main()
{
    int n = 6;
    vector<vector<int>> edges = {{0, 1, 10}, {0, 2, 1}, {2, 3, 1}, {1, 3, 1}, {1, 4, 1}, {4, 5, 10}};
    // vector<vector<int>> edges = {{0, 1, 2}, {0, 4, 8}, {1, 2, 3}, {1, 4, 2}, {2, 3, 1}, {3, 4, 1}};
    int distanceThreshold = 20;
    cout << "Ans: " << findTheCity(n, edges, distanceThreshold);
    return 0;
}
