#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
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

vector<int> ans;
unordered_map<int, TreeNode *> parent; // son(n->val) => parent
unordered_set<int> visit; // Record visited node, store just int val(unique).

void findParent(TreeNode *node)
{
    if (!node)
        return;

    if (node->left)
    {
        parent[node->left->val] = node;
        findParent(node->left);
    }

    if (node->right)
    {
        parent[node->right->val] = node;
        findParent(node->right);
    }
}

void dfs(TreeNode *node, int k)
{
    if (!node || visit.find(node->val) != visit.end())
        return;

    visit.insert(node->val);
    if (k == 0)
    {
        ans.push_back(node->val);
        return;
    }

    dfs(node->left, k - 1);
    dfs(node->right, k - 1);
    dfs(parent[node->val], k - 1);
}

vector<int> distanceK(TreeNode *root, TreeNode *target, int k)
{
    if (!root)
        return {};

    findParent(root);
    dfs(target, k);
    return ans;
}

int main()
{
    return 0;
}
