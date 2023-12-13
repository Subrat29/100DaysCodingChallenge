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

void preorder(TreeNode *&root, vector<int> &v, int depth)
{
    if (root == nullptr)
        return;

    if (v.size() == depth)
        v.push_back(root->val);

    preorder(root->right, v, depth + 1);
    preorder(root->left, v, depth + 1);
}

vector<int> rightSideView(TreeNode *root)
{
    vector<int> v;
    preorder(root, v, 0);
    return v;
}

int main()
{
    return 0;
}
