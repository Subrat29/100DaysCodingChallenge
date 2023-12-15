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

int preIndex = 0;
int postIndex = 0;
TreeNode *constructFromPrePost(vector<int> &preorder, vector<int> &postorder)
{
    TreeNode *root = new TreeNode(preorder[preIndex++]);

    if (root->val != postorder[postIndex])
        root->left = constructFromPrePost(preorder, postorder);

    if (root->val != postorder[postIndex])
        root->right = constructFromPrePost(preorder, postorder);

    postIndex++;
    return root;
}

int main()
{
    return 0;
}
