#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *reverseBetween(ListNode *head, int m, int n)
{
    if (!head || m == n)
        return head;

    ListNode *dummy = new ListNode(0);
    dummy->next = head;
    ListNode *p = dummy;

    // Move to the node before the sublist to be reversed
    for (int i = 0; i < m - 1; ++i)
    {
        p = p->next;
    }

    ListNode *tail = p->next;

    for (int i = 0; i < n - m; ++i)
    {
        ListNode *tmp = p->next;       // a)
        p->next = tail->next;          // b)
        tail->next = tail->next->next; // c)
        p->next->next = tmp;           // d)
    }

    return dummy->next;
}

int main()
{
    return 0;
}
