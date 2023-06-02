#include <bits/stdc++.h>
using namespace std;
#define ll          long long
#define lp(n)       for(ll i = 0; i < (n); ++i)
#define lp1(n)      for(ll i = 1; i <= (n); ++i)
#define tc          ll testcase;   cin>>testcase;   while(testcase--)
#define all(v)      (v).begin(), (v).end()
#define allr(v)     (v).rbegin(), (v).rend()
//#define fi          first
//#define se          second
#define pb          push_back
#define yes         cout<<"YES"<<endl
#define no          cout<<"NO"<<endl
#define improve     ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define Node        ListNode
int dx[4]{-1, 0, 1, 0};
int dy[4]{0, 1, 0, -1};
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

int memo[1001 + 1][1001 + 1];

class Solution {
    string v;
    int n;
public:
    int dp(int i, int j) {
        if (i >= j)
            return 1;

        auto& ret = memo[i][j];
        if (~ret)
            return ret;

        if (v[i] == v[j])
            return ret = dp(i + 1, j - 1);
        
        return ret = 0;
    }

    string longestPalindrome(string s) {
        v = s;
        n = s.size();
        if (n == 1)
            return s;
        memset(memo, -1, sizeof memo);

        int ml = 0, mi = -1, mj = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = i; j < n; ++j) {
                int len = j - i + 1;
                if (dp(i, j) && len > ml) {
                    ml = len;
                    mi = i;
                }
            }
        }

        return s.substr(mi, ml);
    }
};

// int main() {
//     hussein();

//     Solution a;
//     cout << a.longestPalindrome("babad");

//     return 0;
// }

