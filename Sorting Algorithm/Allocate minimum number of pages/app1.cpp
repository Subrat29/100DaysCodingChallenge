#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool isPossible(int A[], int N, int M, long long int curMin)
{
    int studentsRequired = 1;
    int curSum = 0;

    for (int i = 0; i < N; i++)
    {
        if (A[i] > curMin)
            return false;

        if (curSum + A[i] > curMin)
        {
            studentsRequired++;
            curSum = A[i];

            if (studentsRequired > M)
                return false;
        }
        else
        {
            curSum += A[i];
        }
    }
    return true;
}

int findPages(int A[], int N, int M)
{
    if (M > N)
        return -1;

    long long sum = 0;
    for (int i = 0; i < N; i++)
    {
        sum += A[i];
    }

    long long start = 0;
    long long end = sum, mid;
    long long int ans;

    while (start <= end)
    {
        mid = (start + end) / 2;

        if (isPossible(A, N, M, mid))
        {
            ans = ans < mid ? ans : mid;
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }
    return ans;
}

int main()
{
    return 0;
}