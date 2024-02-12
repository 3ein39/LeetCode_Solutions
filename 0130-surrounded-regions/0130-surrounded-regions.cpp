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
	void solve(vector<vector<char>>& board) {
		n = board.size(), m = board[0].size();
		// start from th borders and mark any cc of 'O's with 'E' -> escape them from flips

		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				// continue if not on the border
				if (i > 0 && i < n - 1 && j > 0 && j < m - 1)
					continue;

				if (board[i][j] == 'O')
					dfs(i, j, board, 'E');
			}
		}

		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				if (board[i][j] == 'E')
					board[i][j] = 'O';
				else if (board[i][j] == 'O')
					board[i][j] = 'X';
			}
		}
	}

	void dfs(int i, int j, vector<vector<char>>& mat, char mark) {
		if (!valid(i, j, mat))
			return;

		mat[i][j] = mark;

		for (int k = 0; k < 4; ++k) {
			int ni = i + dx4[k], nj = j + dy4[k];

			dfs(ni, nj, mat, mark);
		}
	}

	bool valid(int i, int j, vector<vector<char>>& mat) {
		if (i < 0 || i >= n  || j < 0 || j >= m  || mat[i][j] == 'X' || mat[i][j] == 'E')
			return false;

		return true;
	}
};

// int main() {
//   hussein();

//   Solution sol;
//   vector<vector<char>> board = {
// 	{'X', 'X', 'X', 'X'},
// 	{'X', 'O', 'O', 'X'},
// 	{'X', 'X', 'O', 'X'},
// 	{'X', 'O', 'X', 'X'}
//   };
//   sol.solve(board);
//   for (auto &row : board) {
// 	cout << row << endl;
//   }


//   return 0;
// }
