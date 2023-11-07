#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<long long int> productExceptSelf(vector<long long int> &nums, int n)
{
	vector<long long int> ans(n, 1); // Initialize the answer vector with 1s.

	// Calculate the product of all elements to the left of the current element.
	long long int leftProduct = 1;
	for (int i = 0; i < n; i++)
	{
		ans[i] *= leftProduct;
		leftProduct *= nums[i];
	}

	// Calculate the product of all elements to the right of the current element.
	long long int rightProduct = 1;
	for (int i = n - 1; i >= 0; i--)
	{
		ans[i] *= rightProduct;
		rightProduct *= nums[i];
	}

	return ans;
}

int main()
{

	return 0;
}