#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

string longestCommonPrefix(vector<string> &strs)
{
    // sort array in Lexicographical order
    sort(strs.begin(), strs.end());

    string s1 = strs[0];
    string s2 = strs[strs.size() - 1];

    int i = 0;
    while ( i < s1.length() && i < s2.length())
    {
        if(s1[i] == s2[i])
        {
            i++;
        }
        else
        {
            break;
        }
    }
    return s1.substr(0,i);
}

int main()
{

    return 0;
}