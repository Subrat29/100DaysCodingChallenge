#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool isPowerOfTwo(int n)
{
    return n > 0 and (n & (n - 1)) == 0;
}

int main()
{

    return 0;
}

// If n is a power of 2:
// n    = 8 (1000)
// n-1  = 7 (0111)
// ----------------
// &    = 0 (0000)