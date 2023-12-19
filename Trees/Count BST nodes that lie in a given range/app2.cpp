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

int getCount(Node *root, int low, int high)
{
    if (root == nullptr)
        return 0;
    if (root->data == low && root->data == high) //without this also works
        return 1;

    if (root->data >= low && root->data <= high)
        return 1 + getCount(root->left, low, high) + getCount(root->right, low, high);

    else if (root->data < low)
        return getCount(root->right, low, high);
    else
        return getCount(root->left, low, high);
}

int main()
{
    return 0;
}
