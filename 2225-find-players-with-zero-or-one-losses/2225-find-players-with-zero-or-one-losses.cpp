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
  public:
	vector<vector<int>> findWinners(vector<vector<int>>& matches) {
		unordered_map<int, pair<int, int>> players; // {player, {win, lose}}
		for (auto& match : matches) {
			int winner = match[0], loser = match[1];
			players[winner].first++, players[loser].second++;
		}

		vector<int> not_lost_a_match, lost_exactly_one_match;
		for (int i = 0; i < 1e6; ++i) {
			if (players.count(i)) {
				if (players[i].second == 0)
					not_lost_a_match.pb(i);
				if (players[i].second == 1)
					lost_exactly_one_match.pb(i);
			}
		}
		
		return {not_lost_a_match, lost_exactly_one_match};
	}
};
