#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool findPair(int arr[], int size, int n)
{
    sort(arr, arr + n);

    int l = 0;
    int r = 1;
    n = abs(n);

    while (l <= r && r < size)
    {
        int diff = arr[r] - arr[l];
        if (diff == n && l != r)
        {
            return true;
        }
        else if (diff > n)
        {
            l++;
        }
        else
        {
            r++;
        }
    }
    return false;
}

int main()
{

    return 0;
}