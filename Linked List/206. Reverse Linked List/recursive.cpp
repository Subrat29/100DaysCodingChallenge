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

ListNode *reverse(ListNode *head)
{
    // base condition
    if (head->next == NULL)
    {
        return head;
    }

    // recursive leap of faith
    ListNode *reverseHead = reverse(head->next);
    head->next->next = head;
    head->next = NULL;
    return reverseHead;
}

ListNode *reverseList(ListNode *head)
{
    if (head == NULL) // i forgot this base case
    {
        return NULL;
    }
    return reverse(head);
}

int main()
{
    return 0;
}
