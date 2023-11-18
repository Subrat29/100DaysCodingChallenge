#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Do it with diagram

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *partition(ListNode *head, int x)
{
    ListNode *Node1 = new ListNode(0);
    ListNode *Node2 = new ListNode(0);
    ListNode *p1 = Node1, *p2 = Node2;

    while (head)
    {
        if (head->val < x)
        {
            p1->next = head;
            p1 = p1->next;
        }
        else
        {
            p2->next = head;
            p2 = p2->next;
        }
        head = head->next;
    }
    p2->next = NULL;
    p1->next = Node2->next;
    return Node1->next;
}

int main()
{
    return 0;
}

// Input: [6,9,0,12,1,4,99,3,2,5,2]
// Output: [0,1,3,2,2,6,9,12,4,99,5]