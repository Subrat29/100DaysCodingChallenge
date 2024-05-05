#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

int main()
{
    // create a map
    map<char, int> mp;

    // insert element
    mp['a'] = 1;
    mp['b'] = 2;
    mp.insert(make_pair('c', 3));
    mp.insert(make_pair('d', 4));

    // Accessing Elements
    cout << mp['a'] << endl;
    cout << mp['b'] << endl;

    // Delete element
    mp.erase('a');

    // Size of map
    int size = mp.size();
    cout << "Size: " << size << endl;

    // Method-1: finding element
    auto it = mp.find('b');
    if (it == mp.end())
        cout << "Not Found" << endl;
    else
        cout << "Found" << endl;

    // Method-2: finding element
    if (mp.count('b'))
        cout << "Found" << endl;
    else
        cout << "Not Found" << endl;

    // Traverse a map
    for (auto &&pair : mp)
    {
        cout << pair.first << ": " << pair.second << endl;
    }

    // Traverse map : by iterator
    for (auto i = mp.begin(); i != mp.end(); i++)
    {
        cout << i->first << ": " << i->second << endl;
    }

    // Clear map : remove all elem
    // mp.clear();

    return 0;
}