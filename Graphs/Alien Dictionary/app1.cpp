#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <list>
using namespace std;

// Class representing a graph
class graph
{
public:
    int V;
    list<int> *adj;

    // Constructor to initialize the graph
    graph(int V)
    {
        this->V = V;
        adj = new list<int>[V];
    }

    // Function to add an edge to the graph
    void addedge(int v, int u)
    {
        adj[v].push_back(u);
    }
};

// Function to determine the dictionary order between two strings and add an edge accordingly
void dictorder(string str1, string str2, graph *g, int *exist)
{
    int n1 = str1.size();
    int n2 = str2.size();

    // Marking the characters in both strings as existing
    for (int i = 0; i < n1; i++)
        exist[(int)str1[i]] = 1;
    for (int i = 0; i < n2; i++)
        exist[(int)str2[i]] = 1;

    int i = 0;
    // Comparing characters in both strings until they are equal
    while (i < n1 && i < n2)
    {
        // If characters are not equal, adding an edge between them in the graph
        if (str1[i] != str2[i])
        {
            g->addedge((int)str1[i], (int)str2[i]);
            return;
        }
        i++;
    }
}

// Function to perform topological sorting using depth-first search
void topsort(list<int> *adj, bool *visited, stack<char> &st, int v,
             int *exist)
{
    // If the character exists, marking it as visited
    if (exist[v])
    {
        visited[v] = true;
        // Recursively exploring adjacent characters
        for (auto u : adj[v])
            if (!visited[u])
                topsort(adj, visited, st, u, exist);
        // Pushing the character onto the stack after exploring all its adjacent characters
        st.push((char)v);
    }
}

// Function to find the correct order of characters using a given array of words
string findOrder(string dict[], int N, int K)
{
    // Creating a graph and an array to track the existence of characters
    graph *g = new graph(256);
    int exist[256] = {0};

    // Determining the dictionary order and adding edges to the graph based on the given words
    for (int i = 1; i < N; i++)
    {
        dictorder(dict[i - 1], dict[i], g, exist);
    }

    // Array to track visited characters during topological sorting
    bool visited[256] = {0};
    // Stack to store the ordered characters
    stack<char> st;
    // Performing topological sorting on the graph
    for (int i = 0; i < 256; i++)
    {
        if (!visited[i])
            topsort(g->adj, visited, st, i, exist);
    }

    string final = "";
    // Constructing the final ordered string by popping characters from the stack
    while (!st.empty())
    {
        final += st.top();
        st.pop();
    }

    return final;
}

int main()
{
    return 0;
}