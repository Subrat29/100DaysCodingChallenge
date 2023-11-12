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

int powerOf2(int n) {
    int result = 1;
    for (int i = 0; i < n; ++i) {
        result *= 2;
    }
    return result;
}

int getDecimalValue(ListNode* head) {
    ListNode* temp = head;
    int l = 0;
    while (temp != nullptr) {
        l++;
        temp = temp->next;
    }

    int ans = 0;
    temp = head;
    int i = l;
    while (temp != nullptr) {
        ans += powerOf2(i - 1) * temp->val;
        temp = temp->next;
        i--;
    }
    return ans;
}

int main()
{
    return 0;
}
