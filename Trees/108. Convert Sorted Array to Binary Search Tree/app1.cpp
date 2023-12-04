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

TreeNode *solve(vector<int> &nums, int low, int high)
{
    if (low > high)
        return nullptr;

    int mid = (low + high) / 2;
    TreeNode *node = new TreeNode(nums[mid]);
    node->left = solve(nums, low, mid - 1);
    node->right = solve(nums, mid + 1, high);
    return node;
}

TreeNode *sortedArrayToBST(vector<int> &nums)
{
    TreeNode *ans = solve(nums, 0, nums.size() - 1);
    return ans;
}

int main()
{
    return 0;
}
