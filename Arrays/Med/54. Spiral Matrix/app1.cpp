#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> spiralOrder(vector<vector<int>> &matrix)
{
    vector<int> ans;

    int totalRow = matrix.size();
    int totalCol = matrix[0].size();
    int total = totalRow * totalCol;
    int cnt = 0;

    int s_row = 0;
    int e_row = totalRow - 1;
    int s_col = 0;
    int e_col = totalCol - 1;

    while (cnt < total)
    {
        // print first row
        for (int i = s_col; cnt < total && i <= e_col; i++)
        {
            ans.push_back(matrix[s_row][i]);
            cnt++;
        }
        s_row++;

        // print last col
        for (int i = s_row; cnt < total && i <= e_row; i++)
        {
            ans.push_back(matrix[i][e_col]);
            cnt++;
        }
        e_col--;

        // print last row
        for (int i = e_col; cnt < total && i >= s_col; i--)
        {
            ans.push_back(matrix[e_row][i]);
            cnt++;
        }
        e_row--;

        // print first col
        for (int i = e_row; cnt < total && i >= s_row; i--)
        {
            ans.push_back(matrix[i][s_col]);
            cnt++;
        }
        s_col++;
    }
    return ans;
}

int main()
{

    return 0;
}