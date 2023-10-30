#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool isPalindrome2(int x)
{
    if (x < 0 || (x != 0 && x % 10 == 0))
        return false;
    int half = 0;
    while (x > half)
    {
        half = half * 10 + x % 10;
        x /= 10;
    }
    return x == half || x == half / 10;
}

int main()
{

    return 0;
}