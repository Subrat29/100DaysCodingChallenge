#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

bool isValid(string s)
{
    stack<char> st;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '(' || s[i] == '{' || s[i] == '[')
        {
            st.push(s[i]);
        }
        else if ((st.empty()) || (s[i] == ')' && st.top() != '(') || (s[i] == '}' && st.top() != '{') || (s[i] == ']' && st.top() != '['))
        {
            return false;
        }
        else
        {
            st.pop();
        }
    }
    return st.empty();
}

int main()
{

    return 0;
}