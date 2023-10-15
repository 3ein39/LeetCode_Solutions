
class Solution {
    int n;
    int dp[501][1000];
    int MOD = 1e9 + 7;
public:
    int solve(int i, int rem) {
        if (i < 0 || i >= n)
        return 0;
        
        if (rem <= 0)
            return i == 0;
        
        auto& ret = dp[i][rem];
        if (~ret) return ret;
        
        ret = 0;
        
        ret = (ret + solve(i + 1, rem - 1)) % MOD;
        ret = (ret + solve(i - 1, rem - 1)) % MOD;
        ret = (ret + solve(i, rem - 1)) % MOD;
        
        return ret;
    }

    int numWays(int steps, int arrLen) {
        memset(dp, -1, sizeof dp);
        arrLen = min(arrLen, steps);
        n = arrLen;
        
        return solve(0, steps);
    }
};