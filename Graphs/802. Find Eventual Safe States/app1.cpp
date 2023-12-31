#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<int> res;
        if (graph.empty()) return res;

        int nodeCount = graph.size();
        vector<int> color(nodeCount, 0);

        for (int i = 0; i < nodeCount; ++i) {
            if (dfs(graph, i, color)) res.push_back(i);
        }

        return res;
    }

    bool dfs(vector<vector<int>>& graph, int start, vector<int>& color) {
        if (color[start] != 0) return color[start] == 1;

        color[start] = 2;
        for (int newNode : graph[start]) {
            if (!dfs(graph, newNode, color)) return false;
        }
        color[start] = 1;

        return true;
    }

int main()
{
    return 0;
}