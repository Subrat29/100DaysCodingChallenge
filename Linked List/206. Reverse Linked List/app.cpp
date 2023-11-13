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

// recursive (simplified version)
ListNode* reverseList(ListNode* head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }

    ListNode* reverseHead = reverseList(head->next);
    head->next->next = head;
    head->next = NULL;

    return reverseHead;
}

int main()
{
    return 0;
}
