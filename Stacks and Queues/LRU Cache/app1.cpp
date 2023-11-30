#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <unordered_map>
using namespace std;

class LRUCache
{
private:
    unordered_map<int, list<pair<int, int>>::iterator> mp;
    list<pair<int, int>> l;
    int size;

public:
    LRUCache(int cap)
    {
        size = cap;
    }
    int GET(int key)
    {
        if (mp.find(key) != mp.end())
        {
            auto it = mp[key];
            pair<int, int> p = *it;
            l.erase(mp[key]);
            l.push_front(p);
            mp[key] = l.begin();
            return (p.second);
        }
        return -1;
    }

    // Function for storing key-value pair.
    void SET(int key, int value)
    {
        if (mp.find(key) != mp.end())
        {
            l.erase(mp[key]);
        }
        else
        {
            if (l.size() == size)
            {
                mp.erase(l.back().first);
                l.pop_back();
            }
        }
        l.push_front({key, value});
        mp[key] = l.begin();
    }
};

int main()
{
    return 0;
}