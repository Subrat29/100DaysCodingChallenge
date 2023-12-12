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

void inorder(TreeNode *root, vector<int> &v)
{
    if (root == nullptr)
        return;

    inorder(root->left, v);
    v.push_back(root->val);
    inorder(root->right, v);
}

bool isValidBST(TreeNode *root)
{
    vector<int> v;
    inorder(root, v);

    vector<int> u = v;
    sort(u.begin(), u.end());
    return u == v;
}

int main()
{
    return 0;
}
