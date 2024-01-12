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
		vector<int> v;
		int n, memo[101][2][2]; // {i, can, bool for isFirstTaken}
  public:
	int rob(vector<int>& nums) {
		v = nums, n =  v.size();
		memset(memo, -1, sizeof memo);

		return solve(0);
	}

	int solve(int i, bool can = true, bool first = false) {
		if (i >= n) {
			return 0;
		}

		auto& ret = memo[i][can][first];
		if (~ret)
			return ret;

		ret = 0;


		ret = max(solve(i + 1, true, first), ret);
		if (i == n - 1 && first) return ret;
		if (can) {
			ret = max(ret, v[i] + solve(i + 1, false, i == 0 || first));
		}

		return ret;
	}
};
