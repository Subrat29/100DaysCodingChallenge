#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int countStudents(vector<int> &students, vector<int> &sandwiches)
{
    int idx = 0;
    int notEatStudent = 0;
    queue<int> q;
    for (int i = 0; i < students.size(); i++)
        q.push(students[i]);

    while (q.size() && notEatStudent != q.size())
    {
        if (q.front() == sandwiches[idx])
        {
            q.pop();
            idx++;
            notEatStudent = 0;
        }
        else
        {
            q.push(q.front());
            q.pop();
            notEatStudent++;
        }
    }
    return q.size();
}

int main()
{
    return 0;
}