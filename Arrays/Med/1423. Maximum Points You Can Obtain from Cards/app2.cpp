#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

    int maxScore(vector<int> & cardPoints, int k)
    {
        int totalPoint = 0;

        // first k elemts in window
        for (int i = 0; i < k; i++)
        {
            totalPoint += cardPoints[i];
        }

        int currPoint = totalPoint;

        for (int i = k - 1; i >= 0; i--)
        {
            // remove last visited elem
            currPoint -= cardPoints[i];

            // & add nonvisited from last
            currPoint += cardPoints[cardPoints.size() - k + i];

            // check max value of any all combination
            totalPoint = max(totalPoint, currPoint);
        }
        return totalPoint;
    }


int main()
{

    return 0;
}