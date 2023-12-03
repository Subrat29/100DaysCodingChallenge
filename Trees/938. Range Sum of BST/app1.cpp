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

void solve(TreeNode *root, int low, int high, int &sum)
{
    if (root == nullptr)
        return;

    solve(root->left, low, high, sum);
    if (root->val >= low && root->val <= high)
        sum += root->val;
    solve(root->right, low, high, sum);
}

int rangeSumBST(TreeNode *root, int low, int high)
{
    int sum = 0;
    solve(root, low, high, sum);
    return sum;
}

int main()
{
    return 0;
}
