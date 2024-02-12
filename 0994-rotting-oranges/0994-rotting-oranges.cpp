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
  public:
	int orangesRotting(vector<vector<int>> &grid) {
		// dfs from all rottens (2)
		// convert each adj (1) into (2)
		// if ∃(1) in mat, return -1
		// use bfs to get minimum number
		n = grid.size(), m = grid[0].size();


		queue<pair<int, int>> q;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				if (grid[i][j] == 2)
					q.push({i, j});
			}
		}


		int minutes = 0;
		while (!q.empty()) {
			int sz = q.size();
			bool changed = false;
			while (sz--) {
				auto node = q.front();
				q.pop();

				for (int k = 0; k < 4; ++k) {
					int ni = node.first + dx4[k], nj = node.second + dy4[k];
					if (valid(ni, nj, grid))
						q.push({ni, nj}), changed = true, grid[ni][nj] = 2;
				}
			}
			if (changed)
				++minutes;
		}

		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				if (grid[i][j] == 1)
					return -1;
			}
		}

		return minutes;
	}

	bool valid(int i, int j, vector<vector<int>>& mat) {
		if (i < 0 || i >= n || j < 0 || j >= m || mat[i][j] == 0 || mat[i][j] == 2)
			return false;

		return true;
	}
};
