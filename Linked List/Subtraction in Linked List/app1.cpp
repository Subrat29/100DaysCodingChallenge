#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Tried this but it fails here: long long int (range)

struct Node
{
    long long int data;
    struct Node *next;

    Node(long long int x)
    {
        data = x;
        next = NULL;
    }
};

Node *subLinkedList(Node *l1, Node *l2)
{
    long long int n1 = 0;
    while (l1)
    {
        n1 = n1 * 10 + l1->data;
        l1 = l1->next;
    }

    long long int n2 = 0;
    while (l2)
    {
        n2 = n2 * 10 + l2->data;
        l2 = l2->next;
    }

    long long int diff = abs(n1-n2);
    string s = to_string(diff);

    Node* head = new Node(-1);
    Node *temp = head;
    for (long long int i = 0; i < s.size(); i++)
    {
        Node *x = new Node(s[i] - '0');
        temp->next = x;
        temp = x;
    }
    return head->next;
}

long long int main()
{
    return 0;
}
