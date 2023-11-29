#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class NestedIterator
{
private:
    stack<vector<NestedInteger>::iterator> begins, ends;

public:
    NestedIterator(vector<NestedInteger> &nestedList)
    {
        begins.push(nestedList.begin());
        ends.push(nestedList.end());
    }

    int next()
    {
        hasNext();
        return (begins.top()++)->getInteger();
    }

    bool hasNext()
    {
        while (begins.size())
        {
            if (begins.top() == ends.top())
            {
                begins.pop();
                ends.pop();
            }
            else
            {
                auto x = begins.top();
                if (x->isInteger())
                    return true;
                begins.top()++;
                begins.push(x->getList().begin());
                ends.push(x->getList().end());
            }
        }
        return false;
    }
};

int main()
{
    return 0;
}
