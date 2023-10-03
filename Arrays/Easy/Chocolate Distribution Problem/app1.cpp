#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
using namespace std;

long long findMinDiff(vector<long long> a, long long n, long long m)
{
    // sort given vector
    sort(a.begin(), a.end());

    long long minDiff = INT_MAX;

    for (int i = 0; i <= a.size()-m; i++)
    {
        // check every window i to i-m-1
        long long windowDiff = a[i+m-1] - a[i];

        if(windowDiff < minDiff)
        {
            minDiff = windowDiff;
        }
    }   
    return minDiff;
}

int main()
{

    return 0;
}