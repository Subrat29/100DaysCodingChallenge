#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int numDistinct(string S, string T)
{
    int m = T.length(); // Length of string T
    int n = S.length(); // Length of string S

    vector<vector<unsigned int>> mem(m + 1, vector<unsigned int>(n + 1, 0));

    // Filling the first row with 1s
    for (int j = 0; j <= n; j++)
    {
        mem[0][j] = 1;
    }

    // Loop through both strings to compute the number of distinct subsequences
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (T[i] == S[j])
            {
                mem[i + 1][j + 1] = mem[i][j] + mem[i + 1][j];
            }
            else
            {
                mem[i + 1][j + 1] = mem[i + 1][j];
            }
        }
    }

    return mem[m][n];
}

int main()
{

    return 0;
}