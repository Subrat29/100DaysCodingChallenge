#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

int calculate(string s)
{
    stack<int> st;
    s += "+";

    int ans = 0;
    int curr = 0;
    char sign = '+';

    for (int i = 0; i < s.length(); i++)
    {
        if (isdigit(s[i]))
        {
            curr = curr * 10 + (s[i] - '0');
        }

        else if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/')
        {
            if (sign == '+')
            {
                st.push(curr);
            }
            else if (sign == '-')
            {
                st.push(curr * (-1));
            }
            else if (sign == '*')
            {
                int num = st.top();
                st.pop();
                st.push(num * curr);
            }
            else if (sign == '/')
            {
                int num = st.top();
                st.pop();
                st.push(num / curr);
            }
            curr = 0;
            sign = s[i];
        }
    }

    while (!st.empty())
    {
        ans += st.top();
        st.pop();
    }
    return ans;
}

int main()
{

    return 0;
}