#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int digitSquareSum(int n)
{
    int sum = 0;
    while (n)
    {
        int rem = n % 10;
        sum += rem * rem;
        n /= 10;
    }
    return sum;
}

bool isHappy(int n)
{
    int slow, fast;
    slow = fast = n;
    do
    {
        slow = digitSquareSum(slow);
        fast = digitSquareSum(fast);
        fast = digitSquareSum(fast);
    } while (slow != fast);

    if (slow == 1)
        return 1;
    else
        return 0;
}

// This can be imagined like two athletes running around a circular field.
// One athlete is running at twice the speed of the other, so there will come
// a time when the faster athlete will again meet the slow athlete .

// The relative speed between them is 1 jump/unit time. So distance between them increases by 1 jump every unit time(1 iteration). Since they are in a cycle, if distance increases at one end, it decreases at the other side of circle, and they meet when it becomes 0.

int main()
{

    return 0;
}