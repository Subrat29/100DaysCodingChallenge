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

ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
{
    if (list1 == NULL)
        return list2;

    if (list2 == NULL)
        return list1;

    ListNode *ans = new ListNode(-1);
    ListNode *temp = ans;

    while (list1 != NULL && list2 != NULL)
    {
        if (list1->val > list2->val)
        {
            temp->next = list2;
            temp = temp->next;
            list2 = list2->next;
        }
        else
        {
            temp->next = list1;
            temp = temp->next;
            list1 = list1->next;
        }
    }
    if (list1 == NULL)
        temp->next = list2;
    else
        temp->next = list1;

    return ans->next;
}

int main()
{
    return 0;
}
