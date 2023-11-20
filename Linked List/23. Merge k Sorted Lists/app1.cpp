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

ListNode *mergeKLists(vector<ListNode *> &lists)
{
    if (lists.size() == 0)
        return nullptr;

    while (lists.size() >= 2)
    {
        lists.push_back(merge2List(lists[0], lists[1]));
        lists.erase(lists.begin());
        lists.erase(lists.begin());
    }
    return lists.front();
}

ListNode *merge2List(ListNode *l1, ListNode *l2)
{
    if (l1 == nullptr)
        return l2;

    if (l2 == nullptr)
        return l1;

    if (l1->val <= l2->val)
    {
        l1->next = merge2List(l1->next, l2);
        return l1;
    }
    else
    {
        l2->next = merge2List(l1, l2->next);
        return l2;
    }
}

int main()
{
    return 0;
}
