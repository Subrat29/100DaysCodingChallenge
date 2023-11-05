#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool checkReverse(vector<int> arr, int n)
{
    int size = arr.size();
    vector<int> copy;
    copy = arr;

    // sort copy array
    sort(copy.begin(), copy.end());
    
    // find first mismatch element in arr
    int front;
    for (front = 0; front < size; front++)
    {
        if(copy[front] != arr[front])
            break;
    }

    // find last mismatch element
    int back;
    for (back = size-1; back >= 0; back--)
    {
        if(copy[back] != arr[back])
            break;
    }

    // checking subarray is in descending orderor not
    do
    {
        front++;
        if(arr[front - 1] < arr[front])
        {
            return false;
        }
    } while (front != back);
    return true;
}

int main() 
{ 
    vector<int> arr;
    arr.push_back(1);
    arr.push_back(2);
    arr.push_back(5);
    arr.push_back(4);
    arr.push_back(3);
    // { 1, 2, 5, 4, 3 }; 
    int n = arr.size(); 
  
    checkReverse(arr, n)? (cout << "Yes" << endl): 
                          (cout << "No" << endl); 
    return 0; 
} 