#include <bits/stdc++.h>
using namespace std;

#define ll          long long
#define lp(n)       for(ll i = 0; i < (n); ++i)
#define lp1(n)      for(ll i = 1; i <= (n); ++i)
#define tc          ll testcase;   cin>>testcase;   while(testcase--)
#define all(v)      (v).begin(), (v).end()
#define allr(v)     (v).rbegin(), (v).rend()
#define watch(num)  cout<< #num <<": "<< num << "\n";
#define pb          push_back
#define yes         cout<<"YES"<<endl
#define no          cout<<"NO"<<endl
#define improve     ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
int dx4[4]{-1, 0, 1, 0};
int dy4[4]{0, 1, 0, -1};
int dx8[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dy8[8] = {0, 1, 1, 1, 0, -1, -1, -1};

template<typename T>
istream &operator>>(istream &input, vector<T> &data) {
	for (T &x : data)input >> x;
	return input;
}

template<typename T>
ostream &operator<<(ostream &output, const vector<T> &data) {
	for (const T &x : data)output << x << " ";
	return output;
}

void hussein() {
	improve;
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
}

class Solution {
		int memo[100000+5];
		vector<int> nums_;
public:
    int minOperations(vector<int>& nums) {
		int n = nums.size();
		sort(all(nums));

		memset(memo, -1, sizeof memo);
		nums_ = nums;
		auto ans = solve(0);
        if (ans == 1e9 || ans == -1) return -1;
		return ans;
    }

	int solve(int i) {
		if (i >= nums_.size())
			return 0;

		auto& ret = memo[i];
		if (~ret)
			return ret;

		ret = 1e9;
		if (i + 1 < nums_.size() && nums_[i] == nums_[i + 1])
			ret = min(ret, solve(i + 2) + 1);

		if (i + 2 < nums_.size() && nums_[i] == nums_[i + 1] && nums_[i + 1] == nums_[i + 2])
			ret = min(ret, solve(i + 3) + 1 );

		return ret;
	}
};

