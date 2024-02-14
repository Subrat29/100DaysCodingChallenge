#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

string solve(int &pos, string s)
{
    int num = 0;
    string word = "";
    while (pos < s.size())
    {
        char ch = s[pos];
        if (ch == '[')
        {
            string str = solve(++pos, s);
            while (num > 0)
            {
                word += str;
                num--;
            }
        }
        else if (ch >= '0' && ch <= '9')
        {
            num = num * 10 + ch - '0';
        }
        else if (ch == ']')
        {
            return word;
        }
        else
        {
            word += ch;
        }
        pos++;
    }
    return word;
}

string decodeString(string s)
{
    int pos = 0;
    return solve(pos, s);
}

int main()
{
    int n = 3;
    while (n--)
    {
        cout << "HOOO" << endl;
    }
    cout << n;

    int num = 3;
    for (; num > 0; num--)
        cout << "hello" << endl;
    cout << num;

    return 0;
}