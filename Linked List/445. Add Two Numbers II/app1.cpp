#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
{
    stack<int> s1, s2;
    while (l1)
    {
        s1.push(l1->val);
        l1 = l1->next;
    }

    while (l2)
    {
        s2.push(l2->val);
        l2 = l2->next;
    }

    ListNode *list = new ListNode(0);
    int sum = 0;
    while (!s1.empty() || !s2.empty())
    {
        if (!s1.empty())
        {
            sum += s1.top();
            s1.pop();
        }
        if (!s2.empty())
        {
            sum += s2.top();
            s2.pop();
        }

        list->val = sum % 10;
        ListNode *head = new ListNode(sum / 10); //star
        head->next = list;
        list = head;
        sum /= 10;
    }
    
    return list->val == 0 ? list->next : list;
}

int main()
{
    return 0;
}

//star: it is because for test case:
//  l1 = [5], l2 = [5]
//  output = [0] (if use: ListNode *head = new ListNode(0);)
//  expected = [1, 0]