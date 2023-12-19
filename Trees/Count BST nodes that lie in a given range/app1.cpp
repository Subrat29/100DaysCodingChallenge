#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

void solve(Node *root, int l, int h, int &cnt)
{
    if (root == nullptr)
        return;

    if (root->data >= l && root->data <= h)
        cnt++;
    solve(root->left, l, h, cnt);
    solve(root->right, l, h, cnt);
}

int getCount(Node *root, int l, int h)
{
    int cnt = 0;
    solve(root, l, h, cnt);
    return cnt;
}

int main()
{
    return 0;
}
