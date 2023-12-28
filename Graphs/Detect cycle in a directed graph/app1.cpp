#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool isCyclicUtil(int v, vector<bool> &visited, vector<bool> &recStack, vector<int> adj[])
{
    // if the current vertex is not visited.
    if (visited[v] == false)
    {
        // marking the current node as visited and part of recursion stack.
        visited[v] = true;
        recStack[v] = true;

        // calling function recursively for all the vertices
        // adjacent to this vertex.
        for (int i = 0; i < (int)adj[v].size(); ++i)
        {
            if (!visited[adj[v][i]] &&
                isCyclicUtil(adj[v][i], visited, recStack, adj))
                return true;
            else if (recStack[adj[v][i]])
                return true;
        }
    }
    // removing the vertex from recursion stack.
    recStack[v] = false;
    return false;
}

// Function to detect cycle in a directed graph.
bool isCyclic(int V, vector<int> adj[])
{
    // marking all vertices as not visited and not a part of recursion stack
    vector<bool> visited(V, false);
    vector<bool> recStack(V, false);

    // calling the recursive helper function to detect cycle in
    // different DFS trees.
    for (int i = 0; i < V; i++)
        if (isCyclicUtil(i, visited, recStack, adj))
            return true;

    return false;
}

int main()
{
    return 0;
}