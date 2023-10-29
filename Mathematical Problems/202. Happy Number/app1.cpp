#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

    // This is hack
    bool isHappy(int n) {
    if (n == 1)
        return true;

    if(n < 5)
        return false;

    int num = 0;
    while(n)
    {
        int rem = n % 10;
        num += rem * rem;
        n = n / 10;
    }

    return isHappy(num); 
    }

int main()
{

    return 0;
}