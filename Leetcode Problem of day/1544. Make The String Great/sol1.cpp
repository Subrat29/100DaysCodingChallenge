#include <iostream>
#include <string>
using namespace std;

string makeGood(string s)
{
    int cnt = 1;
    while (cnt > 0 && s.length() > 1)
    {
        for (int i = 0; i <= s.length() - 2; i++)
        {
            if (s[i] + 0 == s[i + 1] + 32 || s[i] + 32 == s[i + 1] + 0)
            {
                s.erase(i, 2);
                cnt++;
                break;
            }
        }
        cnt--;
    }
    return s;
}

int main()
{
    string s = "abBAcC";
    cout << "Ans: " << makeGood(s);

    return 0;
}
