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

ListNode *reverseKGroup(ListNode *head, int k)
{
    ListNode *begin;
    if (head == nullptr || head->next == nullptr || k == 1)
    {
        return head;
    }

    ListNode *dummyhead = new ListNode(-1);
    dummyhead->next = head;
    begin = dummyhead;
    int i = 0;

    while (head != nullptr)
    {
        i++;
        if (i % k == 0)
        {
            begin = reverse(begin, head->next);
            head = begin->next;
        }
        else
        {
            head = head->next;
        }
    }
    return dummyhead->next;
}

ListNode *reverse(ListNode *begin, ListNode *end)
{
    ListNode *curr = begin->next;
    ListNode *next, *first;
    ListNode *prev = begin;
    first = curr;
    while (curr != end)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    begin->next = prev;
    first->next = curr;
    return first;
}

int main()
{
    return 0;
}
