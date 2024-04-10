#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int timeRequiredToBuy(vector<int> &tickets, int k)
{
    int ans = 0;
    for (int i = 0; i < tickets.size(); i++)
    {
        ans += min(tickets[k] - (i > k), tickets[i]);
    }
    return ans;
}

int main()
{
    return 0;
}