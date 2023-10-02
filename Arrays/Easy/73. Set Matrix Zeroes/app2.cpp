#include <iostream>
#include <vector>
#include <list>
using namespace std;

// sc : m+n

void setZeroes(vector<vector<int>> &matrix) // m x n matrix
{
    int totalRow = matrix.size();
    int totalCol = matrix[0].size();

    vector<int> rowArray(totalRow, 1);
    vector<int> colArray(totalCol, 1);

    for (int i = 0; i < totalRow; i++)
    {
        for (int j = 0; j < totalCol; j++)
        {
            if (matrix[i][j] == 0)
            {
                rowArray[i] = colArray[j] = 0;
            }
        }
    }

    for (int i = 0; i < totalRow; i++)
    {
        for (int j = 0; j < totalCol; j++)
        {
            if (rowArray[i] == 0 || colArray[j] == 0)
            {
                matrix[i][j] = 0;
            }
        }
    }
}

int main()
{
    return 0;
}