#include <bits/stdc++.h>

using namespace std;

#define ull         unsigned long long
#define ll          long long
#define lp(n)       for(ll i = 0; i < (n); ++i)
#define lp1(n)      for(ll i = 1; i <= (n); ++i)
#define tc          ll testcase;   cin>>testcase;   while(testcase--)
#define all(v)      (v).begin(), (v).end()
#define watch(num)  cout<< #num <<": "<< num << "\n";
#define allr(v)     (v).rbegin(), (v).rend()
#define pb          push_back
#define improve     ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
int dx[4]{-1, 0, 1, 0};
int dy[4]{0, 1, 0, -1};

template<typename T>
istream &operator>>(istream &input, vector<T> &data) {
      for (T &x: data)input >> x;
	return input;
}

template<typename T>
ostream &operator<<(ostream &output, const vector<T> &data) {
	for (const T &x: data)output << x << " ";
	return output;
}

void hussein() {
	improve;
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
}
/* 3ein39
                    " وَأَن لَّيْسَ لِلْإِنسَانِ إِلَّا مَا سَعَى ﴿39﴾ وَأَنَّ سَعْيَهُ سَوْفَ يُرَى ﴿40﴾ ثُمَّ يُجْزَاهُ الْجَزَاء الْأَوْفَى "
                                      My way to My dream....
*/

class Solution {
   public:
    bool can1(int el, int target) {
	  return el >= target;
    }

  bool can2(int el, int target) {
	return el <= target;
  }
    vector<int> searchRange(vector<int>& nums, int target) {
		int first = -1, last = -1;

	    ll l = 0, r = nums.size() - 1;
	    while (l <= r) {
	      ll mid = (l + r) / 2;
	      if (can1(nums[mid], target))
		    first = mid, r = mid - 1;
	      else
		    l = mid + 1;
	    }
	    if (first != -1 && nums[first] != target) first = -1;

	    l = 0, r = nums.size() - 1;
		while (l <= r) {
		  ll mid = (l + r) / 2;
		  if (can2(nums[mid], target))
			last = mid, l = mid + 1;
		  else
			r = mid - 1;
		}

      if (last != -1 && nums[last] != target) last = -1;
		return {first, last};
    }
};

// int main() {
// 	hussein();

// 	return 0;
// }
