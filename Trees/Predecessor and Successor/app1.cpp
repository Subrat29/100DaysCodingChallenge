#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Node
{
    int key;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        key = x;
        left = NULL;
        right = NULL;
    }
};

void inorder(Node *root, vector<Node *> &arr)
{
    if (root == nullptr)
        return;
    inorder(root->left, arr);

    arr.push_back(root);

    inorder(root->right, arr);
}
void findPreSuc(Node *root, Node *&pre, Node *&suc, int key)
{
    // Your code goes here
    vector<Node *> arr;
    inorder(root, arr);
    suc = pre = nullptr;
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i]->key == key)
        {
            if (i == 0)
            {
                pre = nullptr;
            }
            else
            {
                pre = arr[i - 1];
            }
            if (i == arr.size() - 1)
            {
                suc = nullptr;
            }
            else
            {
                suc = arr[i + 1];
            }
            break;
        }
        else if (arr[i]->key < key)
        {
            pre = arr[i];
        }
        else
        {
            suc = arr[i];
            break;
        }
    }
}

int main()
{
    return 0;
}
