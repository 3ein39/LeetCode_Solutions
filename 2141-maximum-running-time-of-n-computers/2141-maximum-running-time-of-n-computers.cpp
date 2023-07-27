#define all(v)      (v).begin(), (v).end()

# define ll long long
class Solution {
public:
    long long maxRunTime(int n, vector<int>& batteries) {
    long long l= 1, r = accumulate(all(batteries), 0*1ll)/n, ans = -1;
    	while(l <= r) {
    		long long mid = l + (r - l) /2;

    		long long extra = 0;
    		for (auto& bat : batteries)
    			extra += min(bat*1ll, mid);

    		if (extra >= mid * n)
    			ans = mid, l = mid + 1;
    		else 
    			r = mid - 1;
    	}
    	return ans;
    }
};