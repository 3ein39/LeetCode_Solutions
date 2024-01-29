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
	bool checkInclusion(string s1, string s2) {
		if (s1.size() > s2.size())
			return false;

		vector<int> s1_freq(26, 0), window_freq(26, 0);
		for (auto& el : s1)
			s1_freq[el - 97]++;

		int l = 0, r = 0;
		while (r < s1.size()) {
			window_freq[s2[r] - 97]++;
			r++;
		}
        r--;
        
		if (s1_freq == window_freq) return true;
		++l, ++r;
		while (r < s2.size()) {
			// discard element at l - 1
			window_freq[s2[l - 1] - 97]--;

			// append the new element at r
			window_freq[s2[r] - 97]++;

			// check
			if (s1_freq == window_freq) return true;

			// get next window
			++l, ++r;
		}


		return false;
	}
};

// int main() {
// 	hussein();

// 	Solution sol;
// 	string s1, s2;
// 	s1 = "ab", s2 = "eidbaooo";
// 	cout << sol.checkInclusion(s1, s2) << endl;

// 	return 0;
// }

