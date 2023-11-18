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

ListNode *deleteDuplicates(ListNode *head)
{
    if(head == NULL)
    return NULL;

    ListNode *dummy = new ListNode(0);
    dummy->next = head;
    ListNode *pre = dummy, *curr = head;
    while (curr)
    {
        while (curr->next && curr->val == curr->next->val)
        {
            curr = curr->next;
        }
        if (pre->next == curr)
        {
            pre = pre->next;
        }
        else
        {
            pre->next = curr->next;
        }
        curr = curr->next;
    }
    return dummy->next;
}

int main()
{
    return 0;
}
