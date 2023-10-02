#include <iostream>
#include <vector>
#include <list>
using namespace std;

// sc : O(1)

void setZeroes(vector<vector<int>> &matrix) // m x n matrix
{
    int totalRow = matrix.size();
    int totalCol = matrix[0].size();

    bool isFirstColContainsZero = false;
    bool isFirstRowContainsZero = false;

    // check first column contains zero
    for (int i = 0; i < totalRow; i++)
    {
        if (matrix[i][0] == 0)
        {
            isFirstColContainsZero = true;
            break;
        }
    }

    // check first row contains zero
    for (int i = 0; i < totalCol; i++)
    {
        if (matrix[0][i] == 0)
        {
            isFirstRowContainsZero = true;
            break;
        }
    }

    // if zero present then track it through firstCol and firstRow
    for (int i = 1; i < totalRow; i++)
    {
        for (int j = 1; j < totalCol; j++)
        {
            if (matrix[i][j] == 0)
            {
                matrix[i][0] = 0;
                matrix[0][j] = 0;
            }
        }
    }

    // Now, do processing using firstCol and firstRow
    for (int i = 1; i < totalRow; i++)
    {
        for (int j = 1; j < totalCol; j++)
        {
            if (matrix[i][0] == 0 || matrix[0][j] == 0)
            {
                matrix[i][j] = 0;
            }
        }
    }

    // Now, set firstCol zero if it contains zero
    if (isFirstColContainsZero)
    {
        for (int i = 0; i < totalRow; i++)
        {
            matrix[i][0] = 0;
        }
    }

    // Now, set firstRow zero if it contains zero
    if (isFirstRowContainsZero)
    {
        for (int i = 0; i < totalCol; i++)
        {
            matrix[0][i] = 0;
        }
    }
}

int main()
{
    return 0;
}