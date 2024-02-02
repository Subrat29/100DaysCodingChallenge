#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void dfs(int i, int j, vector<vector<int>> &image, int newColor, int prevColor)
{
    if (i < 0 || i >= image.size() || j < 0 && j >= image[0].size() || image[i][j] != prevColor || image[i][j] == newColor)
        return;

    image[i][j] = newColor;
    dfs(i + 1, j, image, newColor, prevColor);
    dfs(i - 1, j, image, newColor, prevColor);
    dfs(i, j + 1, image, newColor, prevColor);
    dfs(i, j - 1, image, newColor, prevColor);
}

vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int color)
{
    int prevColor = image[sr][sc];
    dfs(sr, sc, image, color, prevColor);
    return image;
}

int main()
{
    return 0;
}