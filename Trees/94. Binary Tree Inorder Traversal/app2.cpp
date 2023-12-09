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

vector<int> inorderTraversal(TreeNode *root)
{
    vector<int> v;
    stack<TreeNode *> s;
    TreeNode *curr = root;

    while (curr != nullptr || !s.empty())
    {
        while (curr != nullptr)
        {
            s.push(curr);
            curr = curr->left;
        }
        curr = s.top();
        s.pop();
        v.push_back(curr->val);
        curr = curr->right;
    }
    return v;
}

int main()
{
    return 0;
}
