#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;

int distance(vector<int> &p1, vector<int> &p2)
{
    return (p1[0] - p2[0]) * (p1[0] - p2[0]) + (p1[1] - p2[1]) * (p1[1] - p2[1]);
}

bool validSquare(vector<int> &p1, vector<int> &p2, vector<int> &p3, vector<int> &p4)
{
    unordered_set<int> s({distance(p1, p2), distance(p1, p3), distance(p1, p4), distance(p2, p3), distance(p2, p4), distance(p3, p4)});
    return !s.count(0) && s.size() == 2;
}

// Note: The unordered_set ensures that there are no duplicate distances.
// bc 4 equal distance and 2 equal diagonal but atlast it contains only 2 unique distances
// d=√((x_2-x_1)²+(y_2-y_1)²

// Check two conditions:
// The first condition (!s.count(0)) ensures that there are no distances of zero length, which would indicate overlapping points. In a square, no two points should overlap, and distances between distinct points should be non-zero.
// The second condition (s.size() == 2) ensures that there are exactly two unique squared distances in the set. In a valid square, there should be two different distances: one for the sides and one for the diagonals.

int main()
{

    return 0;
}