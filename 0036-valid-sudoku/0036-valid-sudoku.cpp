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
		vector<vector<char>> mat;
		int n ,m;
		map<pair<int, int>, int> squares;
  public:
	bool isValidSudoku(vector<vector<char>>& board) {
		mat = board;
		n = m = 9;

		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				if (mat[i][j] == '.') continue;

				if (i >= 0 && i <= 2 && j >= 0 && j <= 2)
					squares[{i, j}] = 1;
				else if (i >= 0 && i <= 2 && j >= 3 && j <= 5)
					squares[{i, j}] = 2;
				else if (i >= 0 && i <= 2 && j >= 6 && j <= 8)
					squares[{i, j}] = 3;
				else if (i >= 3 && i <= 5 && j >= 0 && j <= 2)
					squares[{i, j}] = 4;
				else if (i >= 3 && i <= 5 && j >= 3 && j <= 5)
					squares[{i, j}] = 5;
				else if (i >= 3 && i <= 5 && j >= 6 && j <= 8)
					squares[{i, j}] = 6;
				else if (i >= 6 && i <= 8 && j >= 0 && j <= 2)
					squares[{i, j}] = 7;
				else if (i >= 6 && i <= 8 && j >= 3 && j <= 5)
					squares[{i, j}] = 8;
				else if (i >= 6 && i <= 8 && j >= 6 && j <= 8)
					squares[{i, j}] = 9;

				// check validity
				if (!validr(i) || !validc(j) || !valids(i, j))
					return false;
			}
		}

		return true;
	}
	bool valids(int i, int j) {
		int sqr = squares[{i, j}];
		int cnt = 0;
		set<char> st;

		for (int k = 0; k < n; ++k) {
			for (int l = 0; l < m; ++l) {
				if (mat[k][l] == '.' || squares[{k, l}] != sqr) continue;

				++cnt;
				st.insert(mat[k][l]);
			}
		}


		return cnt == st.size();
	}

	bool validr(int i) {
		// must be a valid row, i.e no duplicate numbers
		int cnt = 0;
		set<char> st;
		for (int j = 0; j < m; ++j) {
			if (mat[i][j] == '.') continue;

			++cnt;
			st.insert(mat[i][j]);
		}

		return cnt == st.size();
	}

	bool validc(int j) {
		// must be a valid row, i.e no duplicate numbers
		int cnt = 0;
		set<char> st;
		for (int i = 0; i < m; ++i) {
			if (mat[i][j] == '.') continue;

			++cnt;
			st.insert(mat[i][j]);
		}

		return cnt == st.size();
	}
};

// int main() {
// 	hussein();

	

// 	return 0;
// }

