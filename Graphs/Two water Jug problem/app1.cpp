#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

// Function to calculate minimum steps to achieve a certain amount of water in one of the jugs.
int pour(int fromCap, int toCap, int d)
{
    int from = fromCap;
    int to = 0;
    int step = 1;

    // Loop until one of the jugs has the desired amount of water.
    while (from != d && to != d)
    {
        // Find the amount of water that can be transferred from one jug to another.
        int temp = min(from, toCap - to);
        to += temp;
        from -= temp;
        step++;

        // Check if desired amount of water has been achieved.
        if (from == d || to == d)
            break;

        // If one jug becomes empty, refill it and increment the step count.
        if (from == 0)
        {
            from = fromCap;
            step++;
        }

        // If one jug becomes full, empty it and increment the step count.
        if (to == toCap)
        {
            to = 0;
            step++;
        }
    }

    // Return the minimum number of steps required to achieve the desired amount of water.
    return step;
}

// Function to calculate the minimum number of steps required to get the desired amount of water.
int minSteps(int m, int n, int d)
{
    // If one jug has a greater capacity, swap the capacities.
    if (m > n)
        swap(m, n);

    // If desired amount of water is greater than the capacity of the larger jug, it is not possible to achieve it.
    if (d > n)
        return -1;

    // If desired amount of water is not divisible by the greatest common divisor of the jug capacities, it is not possible to achieve it.
    if ((d % gcd(n, m)) != 0)
        return -1; //???

    // Return the minimum steps required by considering two scenarios: pouring m to n and pouring n to m.
    return min(pour(n, m, d), pour(m, n, d));
}

int main()
{
    return 0;
}