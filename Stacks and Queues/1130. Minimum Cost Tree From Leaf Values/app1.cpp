#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <limits.h>
using namespace std;

// In C++, a vector can be a stack.
// A stack is a special case of a vector. A vector can grow indefinitely and elements can be removed at any index. A stack can only have elements removed and inserted at the top.

int mctFromLeafValues(vector<int> &A)
{
    int res = 0;
    vector<int> stack = {INT_MAX};
    for (int a : A)
    {
        while (stack.back() <= a)
        {
            int mid = stack.back();
            stack.pop_back();
            res += mid * min(stack.back(), a);
        }
        stack.push_back(a);
    }
    for (int i = 2; i < stack.size(); ++i)
    {
        res += stack[i] * stack[i - 1];
    }
    return res;
}

int main()
{
    return 0;
}
