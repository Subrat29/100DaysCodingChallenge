#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

// Input: s = "lee(t(c)o)de"

// Input: s = "lee(t(c)o)de)"
// Explanation: "lee(t(co)de)" , "lee(t(c)ode)" would also be

string minRemoveToMakeValid(string s)
{
    stack<char> st;
    int open_parentheses = 0;
    int close_parentheses = 0;

    for (char ch : s)
    {
        if (ch == '(')
            open_parentheses++;
        else if (ch == ')')
            close_parentheses++;

        if (close_parentheses > open_parentheses)
            close_parentheses--;
        else
            st.push(ch);
    }

    // cout << "After 1st pass: " << s << endl;
    s = "";
    while (!st.empty())
    {
        char ch = st.top();
        st.pop();

        if (ch == '(' && open_parentheses > close_parentheses)
            open_parentheses--;
        else
            s.push_back(ch);
    }

    cout << "After 2nd pass: " << s << endl;
    reverse(s.begin(), s.end());
    return s;
}

int main()
{
    return 0;
}