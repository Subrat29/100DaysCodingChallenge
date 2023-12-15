#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int numTrees(int n)
{
    if (n <= 1)
        return 1;

    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        ans += numTrees(i - 1) * numTrees(n - i);
    }
    return ans;
}

int main()
{
    return 0;
}
