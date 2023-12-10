#include <iostream>
#include <vector>
#include <queue>
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

class BSTIterator
{
private:
    queue<int> v;
    void inorder(TreeNode *root, queue<int> &v)
    {
        if (root == nullptr)
            return;

        inorder(root->left, v);
        v.push(root->val);
        inorder(root->right, v);
    }

public:
    BSTIterator(TreeNode *root)
    {
        inorder(root, v);
    }

    int next()
    {
        int num = v.front();
        v.pop();
        return num;
    }

    bool hasNext()
    {
        return !v.empty();
    }
};

int main()
{
    return 0;
}