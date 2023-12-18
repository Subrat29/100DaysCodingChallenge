#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Node
{
    int data;
    Node *left, *right;
};

Node *leastCommonAncestor(Node *root, int a, int b)
{
    if (root == nullptr || root->data == a || root->data == b)
        return root;

    Node *leftLca = leastCommonAncestor(root->left, a, b);
    Node *rightLca = leastCommonAncestor(root->right, a, b);

    if (leftLca == nullptr)
        return rightLca;
    if (rightLca == nullptr)
        return leftLca;
    return root;
}

int leastCommonAncestorDist(Node *root, int n)
{
    if (root == nullptr)
        return -1;

    if (root->data == n)
        return 0;

    int leftDist = leastCommonAncestorDist(root->left, n);
    int rightDist = leastCommonAncestorDist(root->right, n);

    if (leftDist == -1 && rightDist == -1)
        return -1;
    else if (leftDist == -1)
        return rightDist + 1;
    else
        return leftDist + 1;
}

int findDist(Node *root, int a, int b)
{
    // Step1: find Least common ancestor of a, b
    Node *lca = leastCommonAncestor(root, a, b);

    // Step2: find distance from lca to a
    int dist1 = leastCommonAncestorDist(lca, a);

    // Step3: find distance from lca to b
    int dist2 = leastCommonAncestorDist(lca, b);

    return dist1 + dist2;
}

int main()
{
    return 0;
}
