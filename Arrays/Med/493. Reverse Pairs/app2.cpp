#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void merge(vector<int> &nums, int start, int mid, int end, int &reversePairs)
{
    int j = mid + 1;
    for (int i = start; i <= mid; i++)
    {
        while (j <= end && nums[i] > 2 * (long long)nums[j])
        {
            j++;
        }
        reversePairs += j - (mid + 1);
    }

    int k = 0;
    int left = start;
    int right = mid + 1;
    int size = end - start + 1;
    vector<int> temp(size, 0);

    while (left <= mid && right <= end)
    {
        if (nums[left] < nums[right])
        {
            temp[k++] = nums[left++];
        }
        else
        {
            temp[k++] = nums[right++];
        }
    }

    while (left <= mid)
    {
        temp[k++] = nums[left++];
    }
    while (right <= end)
    {
        temp[k++] = nums[right++];
    }

    int m = 0;
    for (int i = start; i <= end; i++)
    {
        nums[i] = temp[m++];
    }
}

void mergeSort(vector<int> &nums, int start, int end, int &reversePairs)
{
    if (start >= end)
    {
        return;
    }

    int mid = (start + end) >> 1; // divide by 2

    mergeSort(nums, start, mid, reversePairs);
    mergeSort(nums, mid + 1, end, reversePairs);
    merge(nums, start, mid, end, reversePairs);
}

int reversePairs(vector<int> &nums)
{
    int reversePairs = 0;
    mergeSort(nums, 0, nums.size() - 1, reversePairs);
    return reversePairs;
}

int main()
{

    return 0;
}