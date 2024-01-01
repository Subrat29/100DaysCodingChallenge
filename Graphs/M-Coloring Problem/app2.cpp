#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool check(int node, int i, vector<int> v[], vector<int> &col)
{
    for (auto child : v[node])
        if (i == col[child])
            return false;

    return true;
}

int dfs(int node, int n, int m, vector<int> v[], vector<int> &col)
{
    if (node == n)
        return true;

    for (int i = 0; i < m; ++i)
        if (check(node, i, v, col))
        {
            col[node] = i;

            if (dfs(node + 1, n, m, v, col))
                return true;

            col[node] = -1;
        }

    return false;
}

// Function to determine if graph can be coloured with at most M colours such
// that no two adjacent vertices of graph are coloured with same colour.
bool graphColoring(bool a[101][101], int m, int n)
{
    vector<int> v[n + 1], col(n + 1, -1);

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (i != j && a[i][j] == 1)
                v[i].push_back(j), v[j].push_back(i);
        }
    }

    return dfs(0, n, m, v, col);
}

int main()
{
    return 0;
}