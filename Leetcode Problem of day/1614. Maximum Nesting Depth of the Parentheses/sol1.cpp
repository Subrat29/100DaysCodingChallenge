#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

int maxDepth(string s)
{
    int cnt = 0, maxCnt = 0;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '(')
            maxCnt = max(maxCnt, ++cnt);
        else if (s[i] == ')')
            cnt--;
    }
    return maxCnt;
}

int main()
{
    return 0;
}