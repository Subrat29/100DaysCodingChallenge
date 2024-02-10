#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

// TLE: 10/20

void print(queue<pair<int, int>> q)
{
    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        cout << x << ", " << y << endl;
    }
    cout << endl;
}

bool isValid(int x, int y, int N, vector<vector<bool>> chessBoard)
{
    return (x >= 1 && x <= N && y >= 1 && y <= N && chessBoard[x][y] == false);
}

int minStepToReachTarget(vector<int> &KnightPos, vector<int> &TargetPos, int N)
{
    vector<vector<bool>> chessBoard(N + 1, vector<bool>(N + 1, false));

    int kx = KnightPos[0];
    int ky = KnightPos[1];
    int Tx = TargetPos[0];
    int Ty = TargetPos[1];

    queue<pair<int, int>> q;
    q.push({kx, ky});
    chessBoard[kx][ky] = true;

    int cnt = 0;
    while (!q.empty())
    {
        print(q);
        int len = q.size();
        for (int i = 0; i < len; i++)
        {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();

            cout << "x: " << x << ", y: " << y << endl;

            if (x == Tx && y == Ty)
            {
                return cnt;
            }

            if (isValid(x + 1, y - 2, N, chessBoard))
            {
                chessBoard[x + 1][y - 2] = true;
                q.push({x + 1, y - 2});
            }

            if (isValid(x - 1, y + 2, N, chessBoard))
            {
                chessBoard[x - 1][y + 2] = true;
                q.push({x - 1, y + 2});
            }

            if (isValid(x - 1, y - 2, N, chessBoard))
            {
                chessBoard[x - 1][y - 2] = true;
                q.push({x - 1, y - 2});
            }

            if (isValid(x + 1, y + 2, N, chessBoard))
            {
                chessBoard[x + 1][y + 2] = true;
                q.push({x + 1, y + 2});
            }

            if (isValid(x + 2, y - 1, N, chessBoard))
            {
                chessBoard[x + 2][y - 1] = true;
                q.push({x + 2, y - 1});
            }

            if (isValid(x - 2, y + 1, N, chessBoard))
            {
                chessBoard[x - 2][y + 1] = true;
                q.push({x - 2, y + 1});
            }

            if (isValid(x - 2, y - 1, N, chessBoard))
            {
                chessBoard[x - 2][y - 1] = true;
                q.push({x - 2, y - 1});
            }

            if (isValid(x + 2, y + 1, N, chessBoard))
            {
                chessBoard[x + 2][y + 1] = true;
                q.push({x + 2, y + 1});
            }
        }
        cnt++;
    }
    return -1;
}

int main()
{
    vector<int> KnightPos = {4, 5};
    vector<int> TargetPos = {1, 5};
    int N = 6;
    cout << "Ans: " << minStepToReachTarget(KnightPos, TargetPos, N) << endl;
    return 0;
}
