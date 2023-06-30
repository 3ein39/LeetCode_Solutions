class Solution {
    int n, x;
vector<int> v;
long long memo[1000000+1];
public:
    int coinChange(vector<int>& coins, int amount) {
        n = coins.size(), x = amount;
        v = coins;
          memset(memo, -1, sizeof memo);
    long long ans = dp(x);
    if (ans == 1000000000000000000)
        ans = -1;
        
        return ans;
    }
    long long dp(int rem) {
    if (rem == 0)
        return 0;
    if (rem < 0)
        return 1e18;

    auto& ret = memo[rem];
    if (~ret)
        return ret;

    ret = 1e18;
    for (int j = 0; j < n; j++) {
        if (rem - v[j] >= 0)
            ret = min(ret,1 + dp(rem - v[j]));
    }
    return ret;
}
};