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

ListNode *middleNode(ListNode *head)
{
    ListNode *temp = head;
    int l = 0;
    while (temp != NULL)
    {
        l++;
        temp = temp->next;
    }

    int half = l / 2;
    temp = head;
    while (half--)
    {
        temp = temp->next;
    }
    return temp;
}

int main()
{
    return 0;
}
