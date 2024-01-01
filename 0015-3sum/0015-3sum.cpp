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
	vector<vector<int>> threeSum(vector<int>& nums) {
		vector<vector<int>> answer;

		// no valid pairs
		if (nums.size() < 3)
			return answer;

		sort(all(nums));

		for (int i = 0; i < nums.size() - 2; ++i) {
			// as array is sorted, then no possible answer
			if (nums[i] > 0) break;

			// skip duplicates
			if (i > 0 && nums[i] == nums[i - 1])
				continue;

			// the same 2 sum approach
			int j = i + 1, k = nums.size() - 1;
			while (j < k) {
				int sum = nums[i] + nums[j] + nums[k];
				if (sum < 0)
					++j;
				else if (sum > 0)
					--k;
				else {
					// we found an answer
					answer.push_back({nums[i], nums[j], nums[k]});
					// move the 2 ptrs to find better answer
					
					while (j < k && nums[j] == nums[j + 1]) ++j;
					while (j < k && nums[k] == nums[k - 1]) --k;
					
					++j, --k;
				}
			}
		}
		return answer;
	}
};

