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

bool solve(int sum, TreeNode *root, int target)
{
    if (root == nullptr)
        return false;

    sum += root->val;

    if (root->left == nullptr && root->right == nullptr)
    {
        if (sum == target)
            return true;
        else
            return false;
    }

    return solve(sum, root->left, target) || solve(sum, root->right, target);
}

bool hasPathSum(TreeNode *root, int targetSum)
{
    return solve(0, root, targetSum);
}

int main()
{
    return 0;
}
