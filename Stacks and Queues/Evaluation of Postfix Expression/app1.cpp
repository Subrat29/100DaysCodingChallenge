#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

int evaluatePostfix(string S)
{
    stack<int> st;
    for (int i = 0; i < S.size(); i++)
    {
        if (S[i] == '+' || S[i] == '-' || S[i] == '*' || S[i] == '/')
        {
            int a = st.top();
            st.pop();
            int b = st.top();
            st.pop();

            int c = 0;
            if (S[i] == '+')
            {
                c = a + b;
            }
            else if (S[i] == '-')
            {
                c = b - a;
            }
            else if (S[i] == '*')
            {
                c = a * b;
            }
            else if (S[i] == '/')
            {
                c = b / a;
            }
            st.push(c);
        }
        else
        {
            st.push(S[i] - '0');
        }
    }
    return st.top();
}

int main()
{
    return 0;
}
