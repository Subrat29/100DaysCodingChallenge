#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool isSafe(bool graph[101][101], vector<int> &colorOfNode, int node, int selectedColor, int n)
{
    for (int i = 0; i < n; i++)
    {
        if (graph[node][i] && colorOfNode[i] == selectedColor)
            return false;
    }
    return true;
}

bool solve(bool graph[101][101], vector<int> &colorOfNode, int m, int n, int node)
{
    if (node == n)
        return true;

    for (int colr = 1; colr <= m; colr++)
    {
        if (isSafe(graph, colorOfNode, node, colr, n))
        {
            colorOfNode[node] = colr;

            if (solve(graph, colorOfNode, m, n, node + 1))
                return true;
        }
    }
    return false;
}

bool graphColoring(bool graph[101][101], int m, int n)
{
    vector<int> colorOfNode(n, -1);
    return solve(graph, colorOfNode, m, n, 0);
}

int main()
{
    return 0;
}