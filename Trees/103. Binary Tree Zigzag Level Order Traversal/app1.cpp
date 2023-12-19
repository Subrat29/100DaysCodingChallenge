#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
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

void solve(TreeNode *root, vector<vector<int>> &ans)
{
    int cnt = 1;
    vector<int> v;
    queue<TreeNode *> q;

    q.push(root);
    q.push(nullptr);

    while (!q.empty())
    {
        TreeNode *temp = q.front();
        q.pop();

        if (temp == nullptr)
        {
            if (cnt % 2 == 0)
            {
                reverse(v.begin(), v.end());
            }
            ans.push_back(v);
            v.clear();
            cnt++;
            if (!q.empty())
            {
                q.push(nullptr);
            }
        }
        else
        {
            v.push_back(temp->val);
            if (temp->left)
                q.push(temp->left);
            if (temp->right)
                q.push(temp->right);
        }
    }
}

vector<vector<int>> zigzagLevelOrder(TreeNode *root)
{
    vector<vector<int>> ans;
    if (root)
        solve(root, ans);
    return ans;
}

int main()
{
    return 0;
}
