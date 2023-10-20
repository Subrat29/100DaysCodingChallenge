#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

string reverseWords(string s)
{
    // step1: reverse the whole string
    reverse(s.begin(), s.end());

    int subStrStart = 0;
    int subStrEnd = 0;
    int i = 0;
    int sLength = s.length();

    while (i < sLength)
    {
        while (i < sLength && s[i] != ' ')
        {
            s[subStrEnd++] = s[i++];
        }

        // // if we can find a non-empty word then reverse the current word
        if (subStrEnd > subStrStart)
        {
            reverse(s.begin() + subStrStart, s.begin() + subStrEnd);
            if (subStrEnd == sLength)
            {
                break;
            }
            s[subStrEnd++] = ' ';
            subStrStart = subStrEnd;
        }
        i++;
    }
    if (subStrStart > 0 && s[subStrEnd - 1] == ' ')
    {
        subStrEnd--;
    }
    s.resize(subStrEnd);
    return s;
}

int main()
{

    return 0;
}