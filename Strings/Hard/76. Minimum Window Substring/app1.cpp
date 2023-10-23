#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <limits.h>
using namespace std;

// by @kingsizebeast on leetcode

string minWindow(string s, string t)
{
    unordered_map<char, int> m;

    for (auto c : t)
    {
        m[c]++;
    }

    int start = 0;
    int end = 0;
    int counter = t.size();
    int minStart = 0;
    int minLen = INT_MAX;
    int size = s.size();

    while (end < size)
    {
        if (m[s[end]] > 0)
        {
            counter--;
        }

        m[s[end]]--;
        end++;

        while (counter == 0)
        {
            if (end - start < minLen)
            {
                minStart = start;
                minLen = end - start;
            }
            m[s[start]]++;

            if (m[s[start]] > 0)
            {
                counter++;
            }
            start++;
        }
    }

    if (minLen != INT_MAX)
    {
        return s.substr(minStart, minLen);
    }
    return "";
}

int main()
{

    return 0;
}