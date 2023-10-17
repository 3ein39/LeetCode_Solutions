#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


class Solution {
    vector<int> path;
    int n;
    vector<vector<int>> ans;
public:
    void solve(vector<vector<int>> & graph, int node) {
        if (node == n - 1) {
            ans.push_back(path);
            return;
        }
        
        for (auto& neighbour : graph[node]) {
            path.push_back(neighbour);
            solve(graph, neighbour);
            path.pop_back();
        }
    }

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        n = graph.size();
        
        path.push_back(0);
        
        solve(graph, 0);
        
        return ans;
    }
};