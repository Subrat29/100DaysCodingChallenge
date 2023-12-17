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

// Use postorder traversal

TreeNode *prevNode = nullptr;
void flatten(TreeNode *root)
{
    if (root == nullptr)
        return;

    flatten(root->right);
    flatten(root->left);
    root->right = prevNode;
    root->left = nullptr;
    prevNode = root;
}

int main()
{
    return 0;
}
