#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

// celebrity is known by everyone but he knows no one

int knows(int a, int b, vector<vector<int>> &M)
{
    return M[a][b];
}

int celebrity(vector<vector<int>> &M, int n)
{
    stack<int> s;
    for (int i = 0; i < n; i++)
    {
        s.push(i);
    }

    while (s.size() > 1)
    {
        int a = s.top();
        s.pop();
        int b = s.top();
        s.pop();

        if (knows(a, b, M))
            s.push(b);
        else
            s.push(a);
    }

    int c = s.top();
    for (int i = 0; i < n; i++)
    {
        if (i != c && (knows(c, i, M) || !knows(i, c, M)))
            return -1;
    }
    return c;
}

int main()
{
    return 0;
}
