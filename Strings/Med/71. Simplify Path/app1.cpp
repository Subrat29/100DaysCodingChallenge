#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

string simplifyPath(string path)
{
    stack<string> st;
    string res;

    for (int i = 0; i < path.length(); i++)
    {
        if (path[i] == '/')
        {
            continue;
        }

        string temp;
        // Traverse file name which is in between "/pictures/"
        while (i < path.length() && path[i] != '/')
        {
            temp += path[i];
            i++;
        }

        if (temp == ".")
        {
            continue;
        }

        // remove parent directory or file
        else if (temp == "..")
        {
            if (!st.empty())
            {
                st.pop();
            }
        }

        // push file name to stack
        else
        {
            st.push(temp);
        }
    }

    // add directory or file name to res
    while (!st.empty())
    {
        res = "/" + st.top() + res;
        st.pop();
    }

    // if no directory present
    if (res.length() == 0)
    {
        return "/";
    }

    return res;
}

int main()
{

    return 0;
}