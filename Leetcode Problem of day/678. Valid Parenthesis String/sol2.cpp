#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool checkValidString(string s)
{
    int mini = 0, maxi = 0;
    for (auto &&c : s)
    {
        if (c == '(')
        {
            mini++;
            maxi++;
        }
        else if (c == ')')
        {
            mini--;
            maxi--;
        }
        else
        {
            mini--;
            maxi++;
        }

        if (maxi < 0)
            return false;

        mini = max(mini, 0);
    }
    return mini == 0;
}

int main()
{
    return 0;
}