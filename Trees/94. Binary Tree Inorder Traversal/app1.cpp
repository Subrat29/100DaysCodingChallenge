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

void solve(TreeNode *root, vector<int> &v)
{
    if (root == nullptr)
        return;

    solve(root->left, v);
    v.push_back(root->val);
    solve(root->right, v);
}

vector<int> inorderTraversal(TreeNode *root)
{
    vector<int> v;
    solve(root, v);
    return v;
}

int main()
{
    return 0;
}
