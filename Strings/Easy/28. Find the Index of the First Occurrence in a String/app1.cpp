#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Start at: 8

int strStr(string haystack, string needle)
{
    for (int i = 0; i < haystack.length(); i++)
    {
        if (i + needle.length() > haystack.length())
        {
            break;
        }
        for (int j = 0; j < needle.length(); j++)
        {
            if (haystack[i + j] != needle[j])
            {
                break;
            }
            if (j == needle.length() - 1)
            {
                return i;
            }
        }
    }
    return -1;
}

int main()
{

    return 0;
}