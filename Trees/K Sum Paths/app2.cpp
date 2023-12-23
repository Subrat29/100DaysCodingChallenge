#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

// Recursive utility function to calculate the count of paths with given sum
void sumK_util(Node *root, int sum, int cur, int &ans, unordered_map<int, int> &mp)
{
    if (!root)
        return;

    // Adding the count of paths with current sum difference in the answer
    ans += mp[cur + root->data - sum];

    if (ans >= mod)
        ans %= mod;

    // Checking if the current sum is equal to the desired sum, then incrementing answer
    if (cur + root->data == sum)
        ans++;

    if (ans >= mod)
        ans %= mod;

    // Updating the count of paths with current sum difference
    mp[cur + root->data]++;

    if (mp[cur + root->data] >= mod)
        mp[cur + root->data] %= mod;

    // Recursive calls for left and right subtree
    sumK_util(root->left, sum, cur + root->data, ans, mp);
    sumK_util(root->right, sum, cur + root->data, ans, mp);

    // Backtracking step, decrementing the count of paths with current sum difference
    mp[cur + root->data]--;

    if (mp[cur + root->data] < 0)
        mp[cur + root->data] += mod;
}

// Function to calculate the count of paths with given sum
int sumK(Node *root, int k)
{
    int ans = 0;

    unordered_map<int, int> mp;

    sumK_util(root, k, 0, ans, mp);

    return ans;
}

int main()
{
    return 0;
}
