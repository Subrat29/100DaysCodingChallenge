#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// It is valid solution but not optimized takes 1237ms time

class StockSpanner
{
public:
    vector<int> v;
    StockSpanner()
    {
    }

    int next(int price)
    {
        v.push_back(price);
        int cnt = 0;
        for (int i = v.size() - 1; i >= 0; i--)
        {
            if (v[i] <= price)
                cnt++;
            else
                break;
        }
        return cnt;
    }
};

int main()
{
    return 0;
}
