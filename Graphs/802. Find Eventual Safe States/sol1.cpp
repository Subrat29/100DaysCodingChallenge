#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// by me
bool dfs(int node, vector<bool> &visited, vector<bool> &dfsVisited, vector<vector<int>> &graph)
{
    visited[node] = true;
    dfsVisited[node] = true;
    for (auto &&neighbour : graph[node])
    {
        if (!visited[neighbour])
        {
            if (dfs(neighbour, visited, dfsVisited, graph))
                return true;
        }
        else if (dfsVisited[neighbour])
            return true;
    }
    dfsVisited[node] = false;
    return false;
}

vector<int> eventualSafeNodes(vector<vector<int>> &graph)
{
    int n = graph.size();
    vector<bool> dfsVisited(n, false);
    vector<int> ans;
    for (int i = 0; i < n; i++)
    {
        vector<bool> visited(n, false);
        if (!visited[i])
        {
            if (!dfs(i, visited, dfsVisited, graph))
                ans.push_back(i);
        }
    }
    return ans;
}

int main()
{
    // vector<vector<int>> graph = {{1, 2, 3, 4}, {1, 2}, {3, 4}, {0, 4}, {}};
    // vector<vector<int>> graph = {{1, 2}, {2, 3}, {5}, {0}, {5}, {}, {}};
    vector<vector<int>> graph = {{}, {0, 2, 3, 4}, {3}, {4}, {}};

    vector<int> ans = eventualSafeNodes(graph);
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << ", ";

    return 0;
}