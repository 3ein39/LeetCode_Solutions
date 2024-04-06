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
	int oddCells(int n, int m, vector<vector<int>>& indices) {
		vector<vector<int>> mat(n, vector<int>(m, 0));
		for (auto& v : indices) {
			int x = v[0], y = v[1];
			for (int j = 0; j < m; j++)
				mat[x][j]++;
			for(int i = 0; i < n; ++i)
				mat[i][y]++;
		}
		int ans = 0;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				if (mat[i][j] % 2 != 0)
					++ans;
			}
		}
		
		return ans;
	}
};

// int main() {
// 	hussein();


// 	return 0;
// }
