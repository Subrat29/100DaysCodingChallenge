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

void inorder(struct Node *root, vector<int> &v)
{
    if (!root)
        return;

    inorder(root->left, v);
    v.push_back(root->data);
    inorder(root->right, v);
}

float findMedian(struct Node *root)
{
    vector<int> v;
    inorder(root, v);

    int n = v.size();

    if (n % 2 != 0)
        return (float)v[n / 2];
    else
        return (float)(v[n / 2 - 1] + v[n / 2]) / 2;
}

int main()
{
    return 0;
}
