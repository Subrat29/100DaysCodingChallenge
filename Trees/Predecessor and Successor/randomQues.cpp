#include <iostream>
#include <unordered_set>
using namespace std;

// If the function doesn't need to modify the input string, using const string& is a good practice for consistency and clarity.

string play_game(const string &s)
{
    unordered_set<char> distinct_characters(s.begin(), s.end());
    if (distinct_characters.size() % 2 == 0)
    {
        return "Cricket";
    }
    else
    {
        return "Football";
    }
}

int main()
{
    int t;
    cin >> t;

    for (int i = 0; i < t; ++i)
    {
        string s;
        cin >> s;

        string result = play_game(s);
        cout << result << endl;
    }

    return 0;
}
