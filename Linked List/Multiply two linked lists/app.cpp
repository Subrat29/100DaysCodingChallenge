#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Node
{
    int data;
    Node *next;

    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

#define mod 1000000007
long long multiplyTwoLists(Node *l1, Node *l2)
{
    long long a = 0, b = 0;

    while (l1 != NULL)
    {
        a = ((a * 10)%mod + (l1->data)%mod)%mod;
        l1 = l1->next;
    }

    while (l2 != NULL)
    {
        b = ((b * 10)%mod + (l2->data)%mod)%mod;
        l2 = l2->next;
    }

    return (a%mod*b%mod)%mod;
}

int main()
{
    return 0;
}
