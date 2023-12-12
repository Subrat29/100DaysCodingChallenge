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

bool isValidBST(TreeNode *root)
{
    // reaching null means the BT was valid until we reached the edge of the tree
    if (!root)
        return true;

    long min = LONG_MIN;
    long max = LONG_MAX;
    return validateBST(root, max, min);
}

bool validateBST(TreeNode *root, long max, long min)
{
    if (!root)
    {
        return true;
    }

    if (root->val >= max || root->val <= min)
    {
        return false;
    }

    // valid so continue validating left and right subtrees
    return validateBST(root->left, root->val, min) && validateBST(root->right, max, root->val);
}

int main()
{
    return 0;
}
