#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Not applicable for if test case : [11,49,100,20,86,29,72] , k = 4
int maxScore(vector<int> &cardPoints, int k)
{
    int start = 0;
    int end = cardPoints.size() - 1;
    int totalPoints = 0;

    while (k)
    {
        if (cardPoints[start] > cardPoints[end])
        {
            totalPoints += cardPoints[start++];
        }
        else
        {
            totalPoints += cardPoints[end--];
        }

        k--;
    }
    return totalPoints;
}

int main()
{
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);
    v.push_back(6);
    v.push_back(1);

    int k = 3;

    cout << maxScore(v, k);

    return 0;
}