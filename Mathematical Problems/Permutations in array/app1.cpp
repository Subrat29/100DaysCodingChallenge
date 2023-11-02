#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool isPossible(long long a[], long long b[], int n, long long k)
{
    // sort a in ascending order
    sort(a, a + n);

    // sort b in descending order
    sort(b, b + n, greater<int>());

    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] + b[i] >= k)
            // return false;
            cnt++;
    }
    // return true;
    if (cnt == n)
        return true;
    else
        return false;
}

int main()
{

    return 0;
}