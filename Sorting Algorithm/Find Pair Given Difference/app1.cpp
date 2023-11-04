#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool findPair(int arr[], int size, int n)
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if (abs(arr[i] - arr[j]) == n)
            {
                return true;
            }
        }
    }
    return false;
}

int main()
{

    return 0;
}