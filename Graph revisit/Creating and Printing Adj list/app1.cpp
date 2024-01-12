#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> printAdjacency(int n, int m, vector<vector<int>> &edges)
{
    vector<vector<int>> adjList(n);

    for (int i = 0; i < n; i++)
    {
        adjList[i].push_back(i);
    }
 
    for (auto &&edge : edges)
    {
        int u = edge[0];
        int v = edge[1];

        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
    return adjList;
}

int main()
{
    return 0;
}