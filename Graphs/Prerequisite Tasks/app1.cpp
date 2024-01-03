#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;

vector<unordered_set<int>> makeGraph(int N, int P, vector<pair<int, int>> &prerequisites)
{
    vector<unordered_set<int>> graph(N);
    for (auto &&pre : prerequisites)
    {
        graph[pre.second].insert(pre.first);
    }
    return graph;
}

bool dfsCycle(vector<unordered_set<int>> &graph, int node, vector<bool> &onPath, vector<bool> &visited)
{
    if (visited[node])
        return false;

    visited[node] = onPath[node] = true;
    for (auto &&neighbour : graph[node])
    {
        if (onPath[neighbour] || dfsCycle(graph, neighbour, onPath, visited))
            return true;
    }
    return onPath[node] = false;
}

bool isPossible(int N, int P, vector<pair<int, int>> &prerequisites)
{
    vector<unordered_set<int>> graph = makeGraph(N, P, prerequisites);
    vector<bool> onPath(N, false);
    vector<bool> visited(N, false);
    for (int i = 0; i < N; i++)
    {
        if (!visited[i] && dfsCycle(graph, i, onPath, visited))
            return false;
    }
    return true;
}

int main()
{
    return 0;
}