#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

string convertToTitle(int columnNumber)
{
    string ans = "";
    while (columnNumber)
    {
        columnNumber--;
        int curr = columnNumber % 26;
        columnNumber = columnNumber / 26;
        ans.push_back(curr + 'A');
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

// Note: the reason we need to subtract first instead of modulo first is that Z is in the range of [0, 25].
//       If we don't subtract first and Z happens to be 25, then (Z + 1) % 26 will be 0 and we lose our coefficient.
//       Took me a while to see that.

int main()
{

    return 0;
}