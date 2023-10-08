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
    vector<int> v1,v2;
    int n,m;
    ll memo[501][501];
   public:
    ll dp(int i, int j) {
	  if (i >= n || j >= m)
	    return 0;
	  
	  auto& ret = memo[i][j];
	  if (~ret) return ret;
	  
	  return ret = max({v1[i] * v2[j] + dp(i+1,j+1), dp(i+1,j), dp(i, j+1)});
    }

    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
		int mn1 = *min_element(all(nums1)), mn2 = *min_element(all(nums2));
	    int mx1 = *max_element(all(nums1)), mx2 = *max_element(all(nums2));

	    if (mx1 < 0 && mn2 > 0)
	      return mx1 * mn2;

	    if (mn1 > 0 && mx2 < 0)
	      return mn1 * mx2;

	    v1 = nums1, v2 = nums2;
	    n = v1.size(), m = v2.size();
	    memset(memo, -1, sizeof memo);
	    
	    return dp(0,0);
    }
};

