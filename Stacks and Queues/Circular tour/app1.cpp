#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int tour(petrolPump p[], int n)
{
    int kami = 0;
    int balance = 0;
    int start = 0;

    for (int i = 0; i < n; i++)
    {
        balance += p[i].petrol - p[i].distance;
        if (balance < 0)
        {
            kami += balance;
            start = i + 1;
            balance = 0;
        }
    }
    if (kami + balance >= 0)
    {
        return start;
    }
    return -1;
}

int main()
{
    return 0;
}
