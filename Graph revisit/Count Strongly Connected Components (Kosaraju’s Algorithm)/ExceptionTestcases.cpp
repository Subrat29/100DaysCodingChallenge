#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

// Below approach is nice but not application if component is inside a components like this test case "nested strongly connected components (SCCs)"
// Approach: Not transpose the graph just create a another stack which contains revered elem of prev node
// 5
// 9 11
// 0 3
// 1 7
// 2 5
// 3 6
// 4 1
// 5 8
// 6 0
// 7 4
// 7 5
// 8 6
// 8 2

void dfs(int node, vector<bool> &visited, vector<vector<int>> &adj, stack<int> &s)
{
    visited[node] = true;
    for (auto &&neighbour : adj[node])
    {
        if (!visited[neighbour])
            dfs(neighbour, visited, adj, s);
    }
    s.push(node);
}

void reverseDfs(int node, vector<vector<int>> &adj, vector<bool> &visited)
{
    visited[node] = true;
    for (auto &&neighbour : adj[node])
    {
        if (!visited[neighbour])
            reverseDfs(neighbour, adj, visited);
    }
}

int stronglyConnectedComponents(int v, vector<vector<int>> &edges)
{
    vector<vector<int>> adj(v);
    for (auto &&edge : edges)
    {
        int u = edge[0];
        int v = edge[1];
        adj[u].push_back(v);
    }

    vector<bool> visited(v, false);
    stack<int> s;

    // step1: topo sort
    for (int i = 0; i < v; i++)
    {
        if (!visited[i])
        {
            dfs(i, visited, adj, s);
        }
    }

    // step2: stack gives reversed order so reversed again
    stack<int> topo;
    while (!s.empty())
    {
        topo.push(s.top());
        s.pop();
    }

    for (int i = 0; i < v; ++i)
        visited[i] = false;

    // step3: count scc
    int cnt = 0;
    while (!topo.empty())
    {
        if (!visited[topo.top()])
        {
            cnt++;
            reverseDfs(topo.top(), adj, visited);
        }
        topo.pop();
    }
    return cnt;
}

int main()
{
    return 0;
}