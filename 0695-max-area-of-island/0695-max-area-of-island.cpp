#include <bits/stdc++.h>
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
	  int n, m;
	  vector<vector<int>> v;
	  vector<vector<bool>> vis;
  public:
	int maxAreaOfIsland(vector<vector<int>>& grid) {
		n = grid.size(), m = grid[0].size();
		v = grid;
		vis.resize(n, vector<bool>(m, false));

		int ans = 0;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				if (v[i][j] && !vis[i][j])
					ans = max(ans,dfs(i, j));
			}
		}

		return ans;
	}

	int dfs(int i, int j) {
		if (!valid(i, j))
			return 0;
		
		int sz = 1;
		vis[i][j] = true;
		for (int k = 0; k < 4; ++k) {
			int ni = i + dx4[k], nj = j + dy4[k];
			sz += dfs(ni, nj);
		}
		return sz;
	}

	bool valid(int i, int j) {
		if (i < 0 || j < 0 || i >= n || j >= m || !v[i][j] || vis[i][j])
			return false;

		return true;
	}
};

