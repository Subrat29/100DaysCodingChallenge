#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Max value of Height(leftSubtree)+Height(rightSubtree) (at any node ) is the diameter

int solve(TreeNode *root, int &d)
{
    if (root == NULL)
        return 0;

    int ld = solve(root->left, d);
    int rd = solve(root->right, d);
    d = max(d, ld + rd);
    return max(ld, rd) + 1;
}

int diameterOfBinaryTree(TreeNode *root)
{
    int d = 0;
    solve(root, d);
    return d;
}

int main()
{
    return 0;
}
