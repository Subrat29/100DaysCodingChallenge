#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

int maxDepth(string s)
{
    int cnt = 0;
    stack<char> st;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '(')
            st.push('(');
        else if (s[i] == ')')
        {
            int l = st.size();
            cnt = max(cnt, l);
            st.pop();
        }
    }
    return cnt;
}

int main()
{
    return 0;
}