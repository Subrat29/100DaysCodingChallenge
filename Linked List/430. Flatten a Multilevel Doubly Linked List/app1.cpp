#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Node
{
public:
    int val;
    Node *prev;
    Node *next;
    Node *child;
};

Node *flatten(Node *head)
{
    if (head == NULL)
        return head;

	// Pointer
    Node *p = head;
    
    while (p)
    {
        /* CASE 1: if no child, proceed */
        if (p->child == NULL)
        {
            p = p->next;
            continue;
        }

        /* CASE 2: got child, find the tail of the child and link it to p.next */
        Node *temp = p->child;
        // Find the tail of the child
        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        // Connect tail with p.next, if it is not null
        temp->next = p->next;
        if (p->next != NULL)
        {
            p->next->prev = temp;
        }
        
        // Connect p with p.child, and remove p.child
        p->next = p->child;
        p->child->prev = p;
        p->child = NULL;
    }
    return head;
}

int main()
{
    return 0;
}
