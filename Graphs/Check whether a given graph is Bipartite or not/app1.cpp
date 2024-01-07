#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool dfs(int node, int b, vector<int> graph[], vector<int> &color, int n)
{
    if (b == -1 || color[b] == 0)
        color[node] = 1;
    else
        color[node] = 0;

    for (auto i : graph[node])
    {
        if (color[i] == -1)
        {
            if (dfs(i, node, graph, color, n) == false)
                return false;
        }
        else if (color[i] == color[node])
            return false;
    }
    return true;
}
bool isBipartite(int n, vector<int> graph[])
{
    vector<int> color(n, -1);
    for (int i = 0; i < n; i++)
    {
        if (color[i] == -1)
        {
            if (dfs(i, -1, graph, color, n) == false)
                return false;
        }
    }
    return true;
}

int main()
{
    return 0;
}