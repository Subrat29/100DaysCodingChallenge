#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

string intToRoman(int num)
{
    string thousands[] = {"", "M", "MM", "MMM"};
    string hundreds[] = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
    string tens[] = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
    string ones[] = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};

    return thousands[(num / 1000)] + hundreds[(num % 1000) / 100] + tens[(num % 100) / 10] + ones[(num % 10) / 1];
}

int main()
{

    return 0;
}