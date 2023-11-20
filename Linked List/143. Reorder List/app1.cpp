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

void reorderList(ListNode *head)
{
    if (head == NULL || head->next == NULL || head->next->next == NULL)
        return;

    // Step1: Find middle
    ListNode *p1 = head, *p2 = head;
    while (p2->next && p2->next->next)
    {
        p1 = p1->next;
        p2 = p2->next->next;
    }

    // Step2: Reverse half list after mid
    ListNode *preMid = p1;
    ListNode *preCurr = p1->next;
    while (preCurr->next)
    {
        ListNode *curr = preCurr->next;
        preCurr->next = curr->next;
        curr->next = preMid->next;
        preMid->next = curr;
    }

    // Step3: Reorder list one by one
    p1 = head;
    p2 = preMid->next;
    while (p1 != preMid)
    {
        preMid->next = p2->next;
        p2->next = p1->next;
        p1->next = p2;
        p1 = p2->next;
        p2 = preMid->next;
    }
}

int main()
{
    return 0;
}
