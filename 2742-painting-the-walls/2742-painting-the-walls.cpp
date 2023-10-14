#include <bits/stdc++.h>
using namespace std;


class Solution {
    int dp[501][1000];
    vector<int> c, t;
public:
    int solve(int i, int rem) {
        if (rem <= 0)
            return 0;
        
        if (i >= c.size())
            return 1e9;
            
        auto& ret = dp[i][rem];
        if (~ret) return ret;
        
        return ret = min(solve(i+1, rem), solve(i+1, rem - t[i] - 1) + c[i]);            

    }

    int paintWalls(vector<int>& cost, vector<int>& time) {
        memset(dp, -1, sizeof dp);
        c = cost;
        t = time;
        return solve(0, t.size());
    }
};

