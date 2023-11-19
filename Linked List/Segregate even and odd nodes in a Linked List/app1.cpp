#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int val)
    {
        this->data = val;
    }

    Node()
    {
    }
};

Node *segregateEvenOdd(Node *head)
{
    if (head == nullptr || head->next == nullptr)
        return head;

    Node *Node1 = new Node(0);
    Node *Node2 = new Node(0);
    Node *p1 = Node1, *p2 = Node2;
    Node1->next = head;
    Node2->next = head;

    while (head)
    {
        if (head->data % 2 == 0)
        {
            p2->next = head;
            p2 = head;
        }
        else
        {
            p1->next = head;
            p1 = head;
        }
        head = head->next;
    }

    // only even/odd number are present in list
    if (Node1->next == Node2->next)
        return Node1->next;

    p1->next = Node2->next;
    p2->next = nullptr;
    return Node1->next;
}

void push(Node **head_ref, int new_data)
{
    Node *new_node = new Node();
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

void printList(Node *node)
{
    while (node != NULL)
    {
        cout << node->data << " ";
        node = node->next;
    }
}

int main()
{
    Node *head = NULL;

    push(&head, 11);
    push(&head, 10);
    push(&head, 8);
    push(&head, 6);
    push(&head, 4);
    push(&head, 2);
    push(&head, 0);

    cout << "Original Linked list ";
    printList(head);

    segregateEvenOdd(head);

    cout << "\nModified Linked list ";
    printList(head);

    return 0;
}


// Test Cases
// [1,3,5]
// [8,12,10]
// [8,12,10,5,4,1,6]
// [15,8,12,10,5,4,1,7,6]
