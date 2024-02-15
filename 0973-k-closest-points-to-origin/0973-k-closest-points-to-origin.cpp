#include <bits/stdc++.h>

#include <utility>
using namespace std;

#define ll long long
#define lp(n) for (ll i = 0; i < (n); ++i)
#define lp1(n) for (ll i = 1; i <= (n); ++i)
#define tc         \
  ll testcase;     \
  cin >> testcase; \
  while (testcase--)
#define all(v) (v).begin(), (v).end()
#define allr(v) (v).rbegin(), (v).rend()
#define watch(num) cout << #num << ": " << num << "\n";
#define pb push_back
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#define improve                     \
  ios_base::sync_with_stdio(false); \
  cin.tie(NULL);                    \
  cout.tie(NULL)
int dx4[4]{-1, 0, 1, 0};
int dy4[4]{0, 1, 0, -1};
int dx8[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dy8[8] = {0, 1, 1, 1, 0, -1, -1, -1};

template<typename T>
istream &operator>>(istream &input, vector<T> &data) {
	for (T &x : data) input >> x;
	return input;
}

template<typename T>
ostream &operator<<(ostream &output, const vector<T> &data) {
	for (const T &x : data) output << x << " ";
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
  public:
	vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
		vector<pair<vector<int>, double>> v; // {[x,y], distance};
		for (auto& p : points) {
			int x = p[0], y = p[1];
			auto distance = sqrt(x*x + y*y);
			v.pb({p, distance});
		}


		sort(all(v), [](pair<vector<int>, double>& a, pair<vector<int>, double>& b) {
			if (a.second != b.second)
				return a.second < b.second;

			return a < b;
		});

		vector<vector<int>> ans;
		lp(k) {
			ans.pb(v[i].first);
		}
		return ans;
	}
};
// int main() {
// 	hussein();

// 	// test sol
// 	Solution sol;
// 	vector<vector<int>> points = {{1, 3}, {-2, 2}};
// 	int k = 1;
// 	cout << sol.kClosest(points, k) << endl;


// 	return 0;
// }
