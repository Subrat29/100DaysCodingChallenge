#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

vector<vector<string>> groupAnagrams(vector<string> &strs)
{
    unordered_map<string, vector<string>> mappy;
    for (int i = 0; i < strs.size(); i++)
    {
        string s = strs[i];
        sort(s.begin(), s.end());
        mappy[s].push_back(strs[i]);
    }

    vector<vector<string>> ans;
    for (auto entry : mappy)
    {
        ans.push_back(entry.second);
    }
    return ans;
}

int main()
{

    return 0;
}