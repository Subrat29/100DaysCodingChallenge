#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

string removeDuplicates(string s, int k)
{
    // dummy pair to avoid empty stack
    vector<pair<int, int>> stack = {{0,'#'}};

    for (char c : s)
    {
        if (c != stack.back().second)
        {
            stack.push_back({1, c});
        }
        else
        {
            stack.back().first++;
            if (stack.back().first == k)
                stack.pop_back();
        }
    }

    string res;
    for (auto &p : stack)
    {
        res.append(p.first, p.second);
    }
    return res;
}

// Explanation of string::append:

// The append function is used to add characters to the end of the string.
// The first parameter of append is the count of characters to be appended.
// The second parameter is the character to be appended.

int main()
{
    return 0;
}
