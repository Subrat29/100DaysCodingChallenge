#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

// Agr koi dekh rha h to me ye abhi bhi samaj rha hu 28-11-23🫡

int sumSubarrayMins(vector<int> &arr)
{
    int mod = 1e9 + 7;
    int n = arr.size();
    vector<int> sum(n);
    stack<int> st;
    int j, ans = 0;
    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && arr[st.top()] > arr[i])
            st.pop();
        j = !st.empty() ? st.top() : -1;
        sum[i] = ((j >= 0 ? sum[j] : 0) + (i - j) * arr[i]) % mod;
        st.push(i);
    }
    for (auto it : sum)
        ans = (ans + it) % mod;
    return ans;
}

int main()
{
    return 0;
}
