#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> search(string pat, string txt)
{
    vector<int> ans;

    for (int i = 0; i < txt.length(); i++)
    {
        if (txt[i] == pat[0])
        {
            int idx = i;
            int j = 0;
            while (j < pat.length() && idx < txt.length() && txt[idx] == pat[j])
            {
                idx++;
                j++;
            }
            if (j == txt.length())
            {
                ans.push_back(idx - pat.length() + 1); // Adjust the index by adding 1 to match the 1-based index
            }
        }
    }
    if (!ans.empty())
    {
        return ans;
    }
    else
    {
        return {-1};
    }
}

int main()
{

    return 0;
}