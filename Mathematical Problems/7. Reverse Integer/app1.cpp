#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
using namespace std;

int reverse(int x)
{
    int rev = 0;
    while (x)
    {
        // if (rev > 214748364 || rev < -214748364)
        // {
        //     return 0;
        // }

        if (rev > INT_MAX / 10 || rev < INT_MIN / 10)
        {
            return 0;
        }

        rev = rev * 10 + x % 10;
        x = x / 10;
    }

    return rev;
}

// Note: we devide by 10 because rev ko overflow krne se phle hi check kr le because 22 step pr vo 10 se multiply hone wala h 
// aur error dega

int main()
{

    return 0;
}