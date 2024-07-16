#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// sc: 1
// tc: n

int fibo(int n)
{
    // base case
    int x = 0, y = 1;

    for (int i = 2; i <= n; i++)
    {
        int temp = y;
        y = x + y;
        x = temp;
    }
    return y;
}

// 0 1 1 2 3 5 8 13 21

int main()
{
    int n;
    cin >> n;
    cout << fibo(n);
    return 0;
}