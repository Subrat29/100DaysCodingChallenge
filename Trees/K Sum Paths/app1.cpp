#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

// 1030 /1070
// Time Limit Exceeded

void solve(Node *root, vector<int> &path, int &cnt, int k)
{
    if (root == NULL)
        return;

    path.push_back(root->data);
    solve(root->left, path, cnt, k);
    solve(root->right, path, cnt, k);

    int sum = 0;
    for (int i = path.size() - 1; i >= 0; i--)
    {
        sum += path[i];
        if (sum == k)
            cnt++;
    }
    path.pop_back();
}

int sumK(Node *root, int k)
{
    vector<int> path;
    int cnt = 0;
    solve(root, path, cnt, k);
    return cnt;
}

int main()
{
    return 0;
}
