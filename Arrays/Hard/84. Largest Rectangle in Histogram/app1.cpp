#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

int largestRectangleArea(vector<int> &heights)
{
    stack<int> st;
    int maxArea = 0;
    int i = 0;

    while (i < heights.size())
    {
        if (st.empty() || heights[i] >= heights[st.top()])
        {
            st.push(i);
            i++;
        }
        else
        {
            int tp = st.top();
            st.pop();
            int width = st.empty() ? i : i - st.top() - 1;
            maxArea = max(maxArea, heights[tp] * width);
        }
    }

    while (!st.top())
    {
        int tp = st.top();
        st.pop();
        int width = st.empty() ? i : i - st.top() - 1;
        maxArea = max(maxArea, heights[tp] * width);
    }
}

int main()
{
    vector<int> heights = {2, 1, 5, 6, 2, 3};
    int result = largestRectangleArea(heights);
    cout << "Largest Rectangle Area: " << result << endl;
    return 0;
}