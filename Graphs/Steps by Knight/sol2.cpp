#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct cell
{
    int x;
    int y;
    int cnt;
};

bool isValid(int &x, int &y, int &N, vector<vector<bool>> &chessBoard)
{
    return (x >= 1 && x <= N && y >= 1 && y <= N && chessBoard[x][y] == false);
}

int minStepToReachTarget(vector<int> &KnightPos, vector<int> &TargetPos, int N)
{
    vector<vector<bool>> chessBoard(N + 1, vector<bool>(N + 1, false));
    vector<vector<int>> moves = {{2, 1}, {2, -1}, {-2, 1}, {-2, -1}, {1, 2}, {1, -2}, {-1, 2}, {-1, -2}};

    int kx = KnightPos[0];
    int ky = KnightPos[1];
    int Tx = TargetPos[0];
    int Ty = TargetPos[1];

    queue<cell> q;
    q.push({kx, ky, 0});
    chessBoard[kx][ky] = true;

    while (!q.empty())
    {
        int x = q.front().x;
        int y = q.front().y;
        int cnt = q.front().cnt;
        q.pop();

        if (x == Tx && y == Ty)
            return cnt;

        for (int i = 0; i < moves.size(); i++)
        {
            int a = x + moves[i][0];
            int b = y + moves[i][1];

            if (isValid(a, b, N, chessBoard))
            {
                chessBoard[a][b] = true;
                q.push({a, b, cnt + 1});
            }
        }
    }
    return -1;
}

int main()
{
    return 0;
}