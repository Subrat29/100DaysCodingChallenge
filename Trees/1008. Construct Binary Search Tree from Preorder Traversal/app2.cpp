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

void solve(TreeNode *&root, int data)
{
    if (root == nullptr)
        root = new TreeNode(data);

    else if (data < root->val)  //not use if else
        solve(root->left, data);
    else
        solve(root->right, data);
}

TreeNode *bstFromPreorder(vector<int> &preorder)
{
    TreeNode *root = nullptr;
    for (int i = 0; i < preorder.size(); i++)
    {
        solve(root, preorder[i]);
    }
    return root;
}

int main()
{
    return 0;
}
