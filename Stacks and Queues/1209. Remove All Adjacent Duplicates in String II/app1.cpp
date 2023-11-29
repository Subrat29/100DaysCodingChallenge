#include <iostream>
#include <map>
#include <string>
using namespace std;

// this code is correct if order of output string does not matter but if it is then wrong❌❌

string removeDuplicates(string s, int k) {
    map<char, int> mp;

    // Count occurrences of each character
    for (int i = 0; i < s.size(); i++) {
        mp[s[i]]++;
    }

    string ans = "";

    for (auto it = mp.begin(); it != mp.end(); ++it) {
        // Remove characters with count equal to k
        while (it->second >= k) {
            it->second -= k;
        }

        // Append remaining characters to the result string
        for (int i = 0; i < it->second; ++i) {
            ans += it->first;
        }
    }
    return ans;
}

int main() {
    // string input = "deeedbbcccbdaa";
    // string input = "abcd";
    string input = "pbbcggttciiippooaais";
    int k = 2;
    string result = removeDuplicates(input, k);
    cout << "Result: " << result << endl;

    return 0;
}
