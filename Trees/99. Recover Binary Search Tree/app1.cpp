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

TreeNode *firstElem = nullptr;
TreeNode *secondElem = nullptr;
TreeNode *prevElem = new TreeNode(INT_MIN);

void traverse(TreeNode *root)
{
    if (root == nullptr)
        return;

    traverse(root->left);

    if (firstElem == nullptr && prevElem->val > root->val)
    {
        firstElem = prevElem;
    }

    if (firstElem != nullptr && prevElem->val > root->val)
    {
        secondElem = root;
    }

    prevElem = root;
    traverse(root->right);
}

void recoverTree(TreeNode *root)
{
    traverse(root);

    int temp = firstElem->val;
    firstElem->val = secondElem->val;
    secondElem->val = temp;
}

int main()
{
    return 0;
}
