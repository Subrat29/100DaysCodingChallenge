#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
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

bool isSymmetric(TreeNode *root)
{
    if (root == nullptr)
        return true;

    stack<TreeNode*> s;
    s.push(root->left);
    s.push(root->right);

    while (!s.empty())
    {
        TreeNode *l1 = s.top();
        s.pop();
        TreeNode *l2 = s.top();
        s.pop();

        if (l1 == nullptr && l2 == nullptr)
            continue;

        if (l1 == nullptr || l2 == nullptr || l1->val != l2->val)
            return false;

        s.push(l1->left);
        s.push(l2->right);
        s.push(l1->right);
        s.push(l2->left);
    }
    return true;
}

int main()
{
    return 0;
}
