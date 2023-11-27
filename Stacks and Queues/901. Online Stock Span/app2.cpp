#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

// It is valid solution but not optimized takes 117ms time

class StockSpanner
{
public:
    stack<pair<int, int>> st;
    StockSpanner()
    {
    }

    int next(int price)
    {
        int cnt = 1;
        while (!st.empty() && st.top().first <= price)
        {
            cnt += st.top().second;
            st.pop();
        }
        st.push({price, cnt});
        return cnt;
    }
};

int main()
{
    return 0;
}
