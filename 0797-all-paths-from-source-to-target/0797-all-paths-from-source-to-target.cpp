#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


class Solution {
public:
    void solve(vector<vector<int>> & graph, int node, vector<vector<int>> &ans, vector<int>& path) {
        if (node == graph.size() - 1) {
            ans.push_back(path);
            return;
        }
        
        for (auto& neighbour : graph[node]) {
            path.push_back(neighbour);
            solve(graph, neighbour, ans, path);
            path.pop_back();
        }
    }

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {        
               vector<int> path;
        path.push_back(0);
        vector<vector<int>> ans;

        solve(graph, 0, ans, path);
        
        return ans;
    }
};