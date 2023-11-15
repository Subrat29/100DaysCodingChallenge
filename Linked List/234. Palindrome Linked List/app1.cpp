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

// overflow 63/90 test case
bool isPalindrome(ListNode *head)
{
    long long num = 0;
    ListNode *temp = head;
    while (temp != NULL)
    {
        num = num * 10 + temp->val;
        temp = temp->next;
    }

    long long rev = 0;
    long long originalNum = num;
    while (num)
    {
        rev = rev * 10 + num % 10;
        num /= 10;
    }

    return rev == originalNum;
}

int main()
{
    return 0;
}
