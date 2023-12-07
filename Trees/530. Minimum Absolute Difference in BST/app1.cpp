#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
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

int mini = INT_MAX;
int prev = INT_MAX;

int getMinimumDifference(TreeNode *root)
{
    if (root == nullptr)
        return mini;

    getMinimumDifference(root->left);

    if (prev != INT_MAX)
        mini = min(mini, root->val - prev);

    prev = root->val;

    getMinimumDifference(root->right);
    return mini;
}

int main()
{
    return 0;
}
