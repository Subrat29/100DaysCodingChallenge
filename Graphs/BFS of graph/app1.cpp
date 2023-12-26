#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

vector<int> bfsOfGraph(int V, vector<int> adj[])
{
    // step1: create a visited vector
    vector<bool> vis(V, false);

    // step2: assume a node eg. 0 & mark it to true;
    int s = 0;
    vis[s] = true;

    // step3: create a queue & put that node in queue
    queue<int> q;
    q.push(s);

    // step: create a ans vector to store nodes
    vector<int> ans;

    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        ans.push_back(node);

        // step4: find all neighbours of node & put in queue if it is not visited and mark true
        for (int neighbour : adj[node]) // **confuse here** it traverse all neighbours of 0 -> {1,2,3}
        {
            if (!vis[neighbour])
            {
                vis[neighbour] = true;
                q.push(neighbour);
            }
        }
    }
    return ans;
}

int main()
{
    return 0;
}
