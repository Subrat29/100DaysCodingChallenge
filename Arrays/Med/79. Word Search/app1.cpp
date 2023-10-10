#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

bool search(vector<vector<char>> &board, int i, int j, string word, int idx)
{
    if(idx == word.length())
    {
        return true;
    }

    if (i < 0 || j < 0 || i > board.size()-1 || j > board[0].size()-1 || idx > word.length() || board[i][j] != word[idx])
    {
        return false;
    }

    // Mark for visited
    board[i][j] = '*';

    bool result = search(board, i-1, j, word, idx+1) || search(board, i, j-1, word, idx+1) ||
                  search(board, i+1, j, word, idx+1) || search(board, i, j+1, word, idx+1);

    board[i][j] = word[idx];

    return result;
}

bool exist(vector<vector<char>> &board, string word)
{
    int row = board.size();
    int col = board[0].size();

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (search(board, i, j, word, 0))
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

// It 's just to flip the low 7th bit to indicate whether the current character is visited, as each character can only be used once. It' s similar as setting the current character to 0. Before the loop finish, it flips the bit back again.This can save some memory in case that the target word length is very long so no tmp variables are needed to hold the current char.