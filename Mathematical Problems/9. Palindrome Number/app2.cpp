#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool isPalindrome1(int x)
{
    if (x < 0)
        return false;

    long res = 0;
    int y = x;
    while (y)
    {
        res = res * 10 + y % 10;
        y /= 10;
    }
    return x == res;
}

int main()
{

    return 0;
}