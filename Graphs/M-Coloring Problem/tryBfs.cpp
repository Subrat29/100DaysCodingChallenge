#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

bool graphColoring(bool graph[101][101], int m, int n)
{
    vector<vector<int>> adj(n);
    vector<int> colorOfNode(n, 0);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (graph[i][j] == 1)
            {
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
    }

    vector<int> visited(n, false);
    queue<int> q;
    q.push(0);

    while (!q.empty())
    {
        int node = q.front();
        q.pop();

        for (int clr = 1; clr <= m; clr++)
        {
            bool flag = true;
            for (auto &&nbr : adj[node])
            {
                if (colorOfNode[nbr] == clr)
                {
                    flag = false;
                    break;
                }

                if (!visited[nbr])
                {
                    q.push(nbr);
                    visited[nbr] = true;
                }
            }
            if (flag)
            {
                colorOfNode[node] = clr;
                break;
            }
        }
        if (colorOfNode[node] == 0)
            return false;
    }
    return true;
}

int main()
{
    bool g[101][101];
    g[0][1] = 1;
    g[1][2] = 1;
    g[2][3] = 1;
    g[3][0] = 1;
    g[0][2] = 1;

    bool ans = graphColoring(g, 3, 4);
    cout << "Ans : " << ans;
    return 0;
}