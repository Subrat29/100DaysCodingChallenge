#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <limits.h>
using namespace std;

// Brute force approach

int sumSubarrayMins(vector<int> &arr)
{
    stack<int> st;

    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = i; j < arr.size(); j++)
        {
            int mini = INT_MAX;
            for (int k = i; k <= j; k++)
            {
                mini = min(mini, arr[k]);
            }
            st.push(mini);
        }
    }

    int res = 0;
    while (!st.empty())
    {
        res += st.top();
        st.pop();
    }
    return res;
}

int main()
{
    // vector<int> v = {3, 1, 2, 4};
    vector<int> v = {11, 81, 94, 43, 3};
    cout << sumSubarrayMins(v) << endl;
    return 0;
}
