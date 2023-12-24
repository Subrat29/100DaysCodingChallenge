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

int size(Node *root)
{
    // base case: empty tree has size 0
    if (root == NULL)
    {
        return 0;
    }
    return size(root->left) + 1 + size(root->right);
}

bool isBST(Node *root, int min, int max)
{
    // base case
    if (root == NULL)
    {
        return true;
    }

    if (root->data > min && root->data < max)
    {
        bool left = isBST(root->left, min, root->data);
        bool right = isBST(root->right, root->data, max);
        return left && right;
    }
    else
    {
        return false;
    }
}

int largestBst(Node *root)
{
    if (isBST(root, INT_MIN, INT_MAX))
    {
        return size(root);
    }

    return max(largestBst(root->left), largestBst(root->right));
}

int main()
{
    return 0;
}
