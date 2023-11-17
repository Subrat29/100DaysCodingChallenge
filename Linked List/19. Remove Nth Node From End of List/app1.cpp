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

ListNode *removeNthFromEnd(ListNode *head, int n)
{
    ListNode *fast = head, *slow = head;
    for (int i = 0; i < n; i++)
    {
        fast = fast->next;
    }

    if (fast == NULL)
    {
        return head->next;
    }

    while (fast->next)
    {
        slow = slow->next;
        fast = fast->next;
    }

    ListNode* temp=slow->next;
    slow->next=slow->next->next;
    delete(temp); // free memory also

    return head;
}

int main()
{
    return 0;
}
