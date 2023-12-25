#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
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

TreeNode *solve(vector<int> &preorder, int &i, int parent_val)
{
    if (i == preorder.size() || preorder[i] > parent_val)
        return nullptr;

    int current_val = preorder[i++];
    TreeNode *root = new TreeNode(current_val);
    root->left = solve(preorder, i, current_val);
    root->right = solve(preorder, i, parent_val);
    return root;
}

TreeNode *bstFromPreorder(vector<int> &preorder)
{
    int i = 0;
    return solve(preorder, i, INT_MAX);
}

int main()
{
    return 0;
}
