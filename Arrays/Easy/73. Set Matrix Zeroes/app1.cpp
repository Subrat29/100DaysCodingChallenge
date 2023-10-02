#include <iostream>
#include <vector>
#include <list>
using namespace std;

void setZeroes(vector<vector<int>> &matrix) // m x n matrix
{
    int totalRow = matrix.size();
    int totalCol = matrix[0].size();

    // Worst case sc : O(mn)
    list<pair<int, int>> storeZeroIdx;

    for (int i = 0; i < totalRow; i++)
    {
        for (int j = 0; j < totalCol; j++)
        {
            if (matrix[i][j] == 0)
            {
                storeZeroIdx.push_back(make_pair(i, j));
            }
        }
    }

    // tc : O(n3)
    for (const auto &pair : storeZeroIdx)
    {
        for (int i = 0; i < totalRow; i++)
        {
            for (int j = 0; j < totalCol; j++)
            {
                if (i == pair.first || j == pair.second)
                {
                    matrix[i][j] = 0;
                }
            }
        }
    }
}

int main()
{

    return 0;
}