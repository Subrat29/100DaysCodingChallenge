#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int findParent(int node, vector<int> &parent)
{
    int temp = node;
    while (temp != parent[temp])
        temp = parent[temp];
    parent[node] = temp;
    return temp;
}

vector<int> findRedundantConnection(vector<vector<int>> &edges)
{
    int numNodes = edges.size();
    vector<int> parent(numNodes + 1);
    for (int i = 1; i <= numNodes; i++)
        parent[i] = i;
    for (auto edge : edges)
    {
        int par1 = findParent(edge[0], parent), par2 = findParent(edge[1], parent);
        if (par1 == par2)
            return edge;
        else
            parent[par1] = par2;
    }
    return {};
}

int main()
{
    return 0;
}
