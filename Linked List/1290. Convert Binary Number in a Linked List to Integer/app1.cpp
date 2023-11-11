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

int getDecimalValue(ListNode *head)
{
    ListNode *temp = head;
    int ans = 0;
    while (temp != NULL)
    {
        ans *= 2;
        ans += temp->val;
        temp = temp->next;
    }
    return ans;
}

int main()
{
    return 0;
}
