#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

int romanToInt(string s)
{
    unordered_map<char, int> mp;
    mp['I'] = 1;
    mp['V'] = 5;
    mp['X'] = 10;
    mp['L'] = 50;
    mp['C'] = 100;
    mp['D'] = 500;
    mp['M'] = 1000;

    char prev = s[s.length() - 1];
    int num = 0;
    for (int i = s.length() - 1; i >= 0; i--)
    {
        if (mp[s[i]] < mp[prev])
            num = num - mp[s[i]];
        else
            num = num + mp[s[i]];
        prev = s[i];
    }
    return num;
}

int main()
{
    return 0;
}

// Symbol       Value
// I             1
// V             5
// X             10
// L             50
// C             100
// D             500
// M             1000