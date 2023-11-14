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

Node* compute(Node* head) {
    Node* dummy = new Node(0); // Create a dummy node to serve as the new list's starting point.
    Node* curr = dummy;        // Initialize a pointer to the dummy node.

    while (head != NULL) {
        Node* temp = head;
        int maxi = head->data;

        // Find the maximum value in the current sublist.
        while (temp != NULL) {
            maxi = max(maxi, temp->data);
            if (maxi != head->data) {
                break; // Break if a value different from the current head's value is found.
            }
            temp = temp->next;
        }

        // If the maximum value in the sublist is equal to the head's value, add the node to the new list.
        if (maxi == head->data) {
            Node* temp1 = new Node(head->data);
            curr->next = temp1;
            curr = curr->next;
        }

        head = head->next; // Move to the next node in the original list.
    }

    curr->next = NULL;  // Set the next of the last node to null to terminate the new list.
    return dummy->next; // Return the new list's starting node (skipping the dummy node).
}


int main()
{
    return 0;
}
