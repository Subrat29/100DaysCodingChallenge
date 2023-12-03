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

bool solve(TreeNode *l, TreeNode *r)
{
    if (l == nullptr || r == nullptr)
        return l == r;

    if (l->val != r->val)
        return false;

    return solve(l->left, r->right) && solve(l->right, r->left);
}

bool isSymmetric(TreeNode *root)
{
    return root == nullptr || solve(root->left, root->right);
}

int main()
{
    return 0;
}
