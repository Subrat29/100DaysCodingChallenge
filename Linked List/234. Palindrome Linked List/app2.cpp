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

bool isPalindrome(ListNode *head)
{
    // Step1: Find Middle node
    ListNode *slow = head;
    ListNode *fast = head;
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    // Step2: Reverse right list to the middle
    ListNode *prev = slow, *temp;
    slow = slow->next; 
    prev->next = NULL;
    while (slow)
    {
        temp = slow->next;
        slow->next = prev;
        prev = slow;
        slow = temp;
    }

    fast = head;
    slow = prev;
    while (slow)
    {
        if(slow->val != fast->val)
        return false;
        else
        slow = slow->next;
        fast = fast->next;
    }
    return true;
}

int main()
{
    return 0;
}
