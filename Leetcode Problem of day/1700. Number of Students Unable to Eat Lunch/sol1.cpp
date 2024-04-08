#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int countStudents(vector<int> &students, vector<int> &sandwiches)
{
    bool isUpdate = true;
    int idx = 0;
    queue<int> q;
    for (int i = 0; i < students.size(); i++)
        q.push(students[i]);

    while (isUpdate)
    {
        isUpdate = false;
        int sz = q.size();
        while (sz--)
        {
            if (q.front() == sandwiches[idx])
            {
                q.pop();
                idx++;
                isUpdate = true;
            }
            else
            {
                q.push(q.front());
                q.pop();
            }
        }
    }
    return q.size();
}

int main()
{
    return 0;
}