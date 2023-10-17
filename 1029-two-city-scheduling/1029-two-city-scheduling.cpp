#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        sort(costs.begin(), costs.end(), [](vector<int>& a, vector<int>& b) {
            return (a[0]-a[1] < b[0]-b[1]);
        });
        
        int ans = 0;
        int nn = costs.size();
        for (int i = 0; i < nn/2; ++i) {
            ans += costs[i][0];
        }
        for (int i = 0; i < nn/2; ++i) {
            ans += costs[i + nn/2][1];
        }
        
        return ans;
    }
};