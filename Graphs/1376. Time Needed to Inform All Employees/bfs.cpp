#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

// by bfs
int numOfMinutes(int n, int headID, vector<int> &manager, vector<int> &informTime)
{
    vector<vector<int>> adj(n);
    for (int i = 0; i < n; i++)
        if (manager[i] != -1)
            adj[manager[i]].push_back(i);

    vector<int> timeToReach(n, 0);
    queue<int> q;
    q.push(headID);
    while (!q.empty())
    {
        int parent = q.front();
        q.pop();
        for (auto &&child : adj[parent])
        {
            timeToReach[child] = timeToReach[parent] + informTime[parent];
            q.push(child);
        }
    }
    return *max_element(timeToReach.begin(), timeToReach.end());
}

int main()
{
    return 0;
}