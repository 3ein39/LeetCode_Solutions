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

class TimeMap {
		unordered_map<string, vector<pair<string, int>>> structure;
  public:
	TimeMap() {

	}

	void set(string key, string value, int timestamp) {
		structure[key].pb({value, timestamp});
	}

	string get(string key, int timestamp) {
			// binary search
			if (!structure.count(key)) return "";
			auto& v = structure[key];
			int l = 0, r = v.size() - 1, ans = -1;
			while (l <= r) {
				int mid = l + (r - l) / 2;
				if (v[mid].second < timestamp)
					ans = mid, l = mid + 1;
				else if (v[mid].second == timestamp)
					return v[mid].first;
				else
					r = mid - 1;
			}

			if (ans == -1)
				return "";
			return v[ans].first;
	}
};
