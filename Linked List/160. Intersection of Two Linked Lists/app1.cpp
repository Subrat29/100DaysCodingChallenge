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

// go to leetcode soln for more clarity (visualization soln)
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    if (headA == NULL || headB == NULL) {
        return NULL;
    }

    ListNode *a = headA;
    ListNode *b = headB;

    while (a != b) {
        if (a == NULL) {
            a = headB;
        } else {
            a = a->next;
        }

        if (b == NULL) {
            b = headA;
        } else {
            b = b->next;
        }
    }
    return a;
}


int main()
{
    return 0;
}
