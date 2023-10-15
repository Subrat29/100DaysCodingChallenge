#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
using namespace std;

string shortestBeautifulSubstring(string s, int k)
{
    string ans = "";
    int len = INT_MAX;

    for (int i = 0; i < s.length(); i++)
    {
        int cnt = 0;
        int j = i;
        while (j < s.length() && cnt < k)
        {
            if (s[j] == '1')
            {
                cnt++;
            }
            j++;
        }

        if (cnt == k)
        {
            int currSubstrLen = j - i;
            if (currSubstrLen <= len)
            {
                string currSubstr = s.substr(i, currSubstrLen);
                if (ans == "" || (currSubstr < ans && currSubstrLen == len))
                {
                    ans = currSubstr;
                }
                else if (currSubstrLen < len)
                {
                    ans = currSubstr;
                }
                len = currSubstrLen;
            }
        }
    }

    return ans;
}

int main()
{
    string s = "110101000010110101";
    int k = 3;

    cout << shortestBeautifulSubstring(s, k) << endl;

    return 0;
}