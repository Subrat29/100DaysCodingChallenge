#include <iostream>
#include <stack>
#include <algorithm>
#include <string>
using namespace std;

// 71 / 83 testcases passed
// s = "((((()(()()()*()(((((*)()*(**(())))))(())()())(((())())())))))))(((((())*)))()))(()((*()*(*)))(*)()"

bool checkValidString(string s)
{
    string s1 = s; // (
    string s2 = s; // )

    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '*')
        {
            s1[i] = '(';
            s2[i] = ')';
        }
    }

    stack<char> st1;
    stack<char> st2;
    stack<char> st;

    for (int i = 0; i < s.length(); i++)
    {
        if (s1[i] == '(')
            st1.push(')');
        else if (s1[i] == ')' && !st1.empty() && st1.top() == ')')
            st1.pop();
        else if (s1[i] == ')')
            st1.push('(');

        if (s2[i] == '(')
            st2.push(')');
        else if (s2[i] == ')' && !st2.empty() && st2.top() == ')')
            st2.pop();
        else if (s2[i] == ')')
            st2.push('(');

        if (s[i] == '(')
            st.push(')');
        else if (s[i] == ')' && !st.empty() && st.top() == ')')
            st.pop();
        else if (s[i] == ')')
            st.push('(');
    }
    cout << st.empty() << endl;
    cout << st1.empty() << endl;
    cout << st2.empty() << endl;

    if (st.empty() || st1.empty() || st2.empty())
        return true;
    else
        return false;
}

int main()
{
    string s = "()))()))))(())))";
    cout << "Ans: " << checkValidString(s) << endl;
    return 0;
}