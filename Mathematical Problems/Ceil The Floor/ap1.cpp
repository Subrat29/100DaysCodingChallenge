#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

pair<int, int> getFloorAndCeil(int arr[], int n, int x)
{
    sort(arr, arr + n);

    int low = -1;
    int high = -1;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] <= x)
        {
            low = arr[i];
        }
        if (arr[i] >= x)
        {
            return {low, arr[i]};
        }
    }
    return {low, high};
}

int main()
{

    return 0;
}