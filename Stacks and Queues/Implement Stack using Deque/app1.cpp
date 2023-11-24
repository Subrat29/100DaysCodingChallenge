#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>
using namespace std;

class MyStack
{
    public:
    deque<int> dq;
    MyStack()
    {
    }

    void push(int x)
    {
        dq.push_back(x);
    }

    int pop()
    {
        int x = peek();
        dq.pop_back();
        return x;
    }

    int peek()
    {
        return dq.back();
    }

    bool empty()
    {
        return dq.empty();
    }
};

int main()
{
    MyStack q;
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(1);

    cout << q.pop() << endl;
    cout << q.pop() << endl;
    
    cout << q.peek() << endl;

    cout << q.empty() << endl;

    return 0;
}
