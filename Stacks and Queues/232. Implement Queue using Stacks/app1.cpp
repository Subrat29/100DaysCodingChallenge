#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

class MyQueue
{
    stack<int> input;
    stack<int> output;
    
    MyQueue()
    {
    }

    void push(int x)
    {
        input.push(x);
    }

    int pop()
    {
        int p = peek();
        output.pop();
        return p;
    }

    int peek()
    {
        if(output.empty())
        while (input.size())
        {
            output.push(input.top());
            input.pop();
        }
        return output.top();
    }

    bool empty()
    {
        return input.empty() && output.empty();
    }
};

int main()
{
    return 0;
}
