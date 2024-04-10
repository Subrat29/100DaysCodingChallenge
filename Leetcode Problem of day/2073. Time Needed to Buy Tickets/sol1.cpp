#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int timeRequiredToBuy(vector<int> &tickets, int k)
{
    int totalTime = 0;
    while (tickets[k] != 0)
    {
        for (int i = 0; i < tickets.size(); i++)
        {
            if (tickets[i] > 0)
                totalTime++;
            if (tickets[i] > 0)
                tickets[i]--;
            if (i == k && tickets[k] == 0)
                break;
        }
    }
    return totalTime;
}

int main()
{
    return 0;
}