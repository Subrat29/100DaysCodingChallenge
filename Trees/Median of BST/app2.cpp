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

// c++

int countNodes(Node *n)
{
    // this function returns number of nodes in tree
    if (!n)
        return 0;
    return 1 + countNodes(n->left) + countNodes(n->right);
}

int find(Node *n, int serialNo, int target, int &value)
{
    // this function keeps track of serial number while doing
    // inorder traveresal and finds the target node

    if (!n)
        return serialNo;
    serialNo = find(n->left, serialNo, target, value);

    serialNo++;
    // current value of serialNo variable is the rank of
    // current Node
    if (serialNo == target)
        value = n->data;

    serialNo = find(n->right, serialNo, target, value);
    return serialNo;
}

float findMedian(struct Node *root)
{
    int n = countNodes(root);

    if (n % 2)
    {
        // odd number of nodes in tree:
        // 1+n/2 is the rank of mid node

        int mid = 0;
        find(root, 0, 1 + n / 2, mid);
        return mid;
    }
    else
    {
        // even number of nodes in tree:
        // n/2 and 1+n/2 are the ranks of mid nodes

        int mid1 = 0, mid2 = 0;
        find(root, 0, n / 2, mid1);
        find(root, 0, 1 + n / 2, mid2);
        return ((float)(mid1 + mid2)) / 2.0;
    }
}