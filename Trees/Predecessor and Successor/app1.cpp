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

int main()
{
    return 0;
}
