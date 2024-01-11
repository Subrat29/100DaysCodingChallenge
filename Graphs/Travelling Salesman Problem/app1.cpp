#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
using namespace std;

int tsp(int mask, int pos, int VISITED_ALL, vector<vector<int>> &cost, vector<vector<int>> &dp)
{
    int n = cost.size();

    // Base case: if all the cities have been visited,
    // return the cost of returning to the starting city
    if (mask == VISITED_ALL)
    {
        return cost[pos][0];
    }

    // If the optimal cost for the current mask and position
    // has already been calculated, return it
    if (dp[mask][pos] != -1)
    {
        return dp[mask][pos];
    }

    int ans = INT_MAX;

    // Iterating over all the unvisited cities to take the best route
    for (int city = 0; city < n; city++)
    {

        // Checking if the city has not been visited
        if ((mask & (1 << city)) == 0)
        {

            // Calculating the cost of going from the current position to the city
            // and recursively calculating the optimal cost for the remaining cities
            int newAns = cost[pos][city] + tsp(mask | (1 << city), city, VISITED_ALL, cost, dp);

            // Updating the minimum cost
            ans = min(ans, newAns);
        }
    }

    // Storing the optimal cost for the current mask and position
    dp[mask][pos] = ans;
    return ans;
}

// Function to calculate the total cost for the Traveling Salesman Problem
int total_cost(vector<vector<int>> cost)
{
    int n = cost.size();

    // Initializing the dp array with -1 to store the optimal cost
    vector<vector<int>> dp((1 << n) + 5, vector<int>(n, -1));

    // Creating the mask for all cities visited
    int VISITED_ALL = (1 << n) - 1;

    // Calling the tsp function to calculate the total cost
    return tsp(1, 0, VISITED_ALL, cost, dp);
}

int main()
{
    return 0;
}