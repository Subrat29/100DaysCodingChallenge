#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void dfs(int i, int j, vector<vector<int>> &m, int n, vector<string> &ans, string &path)
{
    if (i < 0 || j < 0 || i >= n || j >= n || m[i][j] == 0)
        return;

    m[i][j] = 0;
    // up
    path.push_back('U');
    dfs(i - 1, j, m, n, ans, path);
    path.pop_back();

    // down
    path.push_back('D');
    dfs(i + 1, j, m, n, ans, path);
    path.pop_back();

    // left
    path.push_back('R');
    dfs(i, j + 1, m, n, ans, path);
    path.pop_back();

    // right
    path.push_back('L');
    dfs(i, j - 1, m, n, ans, path);
    path.pop_back();

    if (i == n - 1 && j == n - 1)
        ans.push_back(path);

    m[i][j] = 1;
}

vector<string> findPath(vector<vector<int>> &m, int n)
{
    // if either source or dest value is 0 then return -1
    if (m[0][0] == 0 || m[n - 1][n - 1] == 0)
        return {"-1"};

    vector<string> ans;
    string path = "";
    dfs(0, 0, m, n, ans, path);
    return ans;
}

int main()
{
    return 0;
}