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

// Runtime: 21ms
int maxPathSum(TreeNode *root)
{
    int maxValue = INT_MIN;
    maxPathDown(root, maxValue);
    return maxValue;
}

int maxPathDown(TreeNode *root, int &maxValue)
{
    if (root == nullptr)
        return 0;

    int left = max(0, maxPathDown(root->left, maxValue));
    int right = max(0, maxPathDown(root->right, maxValue));

    maxValue = max(maxValue, left + right + root->val);
    return max(left, right) + root->val;
}

int main()
{
    return 0;
}
