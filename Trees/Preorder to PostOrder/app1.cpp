#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef struct Node
{
    int data;
    struct Node *left, *right;
} Node;

// A utility function to create a new tree node
Node *newNode(int data)
{
    Node *temp = (Node *)malloc(sizeof(Node));
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

void BST(Node *&root, int data)
{
    if (root == nullptr)
    {
        root = newNode(data);
        return;
    }

    if (root->data > data)
        BST(root->left, data);
    else
        BST(root->right, data);
}

Node *post_order(int pre[], int size)
{
    Node *root = nullptr;
    for (int i = 0; i < size; i++)
    {
        BST(root, pre[i]);
    }
    return root;
}

int main()
{
    return 0;
}
