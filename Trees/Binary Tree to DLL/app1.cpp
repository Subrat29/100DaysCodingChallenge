#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        data = x;
        left = right = NULL;
    }
};

void solve(Node *root, Node *&head, Node *&prev)
{
    if (root == nullptr)
        return;

    solve(root->left, head, prev);

    if (prev == nullptr)
        head = root;
    else
    {
        root->left = prev;
        prev->right = root;
    }

    prev = root;
    solve(root->right, head, prev);
}

Node *bToDLL(Node *root)
{
    Node *head = nullptr;
    Node *prev = nullptr;
    solve(root, head, prev);
    return head;
}

int main()
{
    return 0;
}
