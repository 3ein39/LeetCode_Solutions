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
		string cur;
		int n;
		vector<string> ans;
public:
    vector<string> generateParenthesis(int n_) {
		n = n_ * 2;
		generate(0);

		return ans;
    }

	bool valid() {
		int cnt = 0;
		for (auto& el : cur) {
			if (el == '(')
				++cnt;
			else
				--cnt;
			if (cnt < 0) return false;
		}

		if (cnt != 0)
			return false;
		return true;
	}

	void generate(int i) {
		if (i >= n) {
			if (valid())
				ans.pb(cur);
			return;
		}

		cur.pb(')');
		generate(i + 1);
		cur.pop_back();

		cur.push_back('(');
		generate(i + 1);
		cur.pop_back();
	}
};

// int main() {
// 	hussein();

// 	int n = 3;
// 	Solution().generateParenthesis(n);

// 	return 0;
// }

