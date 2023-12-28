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
	int carFleet(int target, vector<int>& position, vector<int>& speed) {
		// sort based on position
		vector<pair<int, int>> v;
		for (int i = 0; i < position.size(); ++i) {
			v.pb({position[i],speed[i]});
		}

		sort(all(v));

		vector<double> time_finish;
		// calculate time for each position
		for (auto& [pos, spd] : v) {
			double time = (target - pos)/(spd*1.0);
			time_finish.pb(time);
		}
		
		double max_t = 0, res = 0;
		for (int i = time_finish.size() - 1; i >= 0; --i) {
			if (time_finish[i] > max_t) {
				max_t = time_finish[i];
				++res;
			}
		}
		
		return res;
	}
};
