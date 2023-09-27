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
    string decodeAtIndex(string s, int k) {
		// reverse decoding
	    // letter ? sz -= 1
	    // digit  ? sz /= digit
	    
	    ll sz = 0;
	    for (auto& el : s) {
	      if (el >= 'a' && el <= 'z')
		    sz++;
	      else
		    sz *= el - '0';
	    }
	    
	    // iterate reversed or reverse the string then iterate 
	    reverse(all(s));
	    string ans;
	    for (auto& el : s) {
		  if (el >= 'a' && el <= 'z') {
		    if (k == 0 || k == sz)
			  return ans = el;
		    --sz;
	      }
	      else {
		    sz /= el - '0';
		    k %= sz;
	      }
	    }
	    
	    return " ";
    }
};
