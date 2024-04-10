#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;

vector<int> deckRevealedIncreasing(vector<int> &deck)
{
    sort(deck.begin(), deck.end());
    deque<int> d;
    d.push_front(deck.back());
    deck.pop_back();
    while (!deck.empty())
    {
        d.push_front(d.back());
        d.pop_back();
        d.push_front(deck.back());
        deck.pop_back();
    }
    vector<int> ans(d.begin(), d.end());
    return ans;
}

int main()
{
    return 0;
}