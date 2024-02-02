#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<int> bfsOfGraph(int V, vector<int> adj[])
{
    // create visited vector
    vector<int> visited(V, 0);

    // ans vector
    vector<int> ans;

    // create a queue
    queue<int> q;

    visited[0] = true;
    q.push(0);

    // do processing
    while (!q.empty())
    {
        int frontNode = q.front();
        ans.push_back(frontNode);
        q.pop();

        for (auto &&neighbour : adj[frontNode])
        {
            if (visited[neighbour] == false)
            {
                visited[neighbour] = true;
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