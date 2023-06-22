#include <bits/stdc++.h>
using namespace std;
#define ll          long long
#define lp(n)       for(ll i = 0; i < (n); ++i)
#define lp1(n)      for(ll i = 1; i <= (n); ++i)
#define tc          ll testcase;   cin>>testcase;   while(testcase--)
#define all(v)      (v).begin(), (v).end()
#define allr(v)     (v).rbegin(), (v).rend()
#define pb          push_back
#define yes         cout<<"YES"<<endl
#define no          cout<<"NO"<<endl
#define improve     ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
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

class Solution {
public:
    int memo[100000 + 1][3][5];
    enum {BUY1,BUY2, SELL};
    int cost;
    int n;
    vector<int >v;
    int dp(int i, int state, int left) {
        if (i >= n || !left)
            return 0;


        auto& ret = memo[i][state][left];
        if (~ret)
            return ret;

        ret = 0;

        if (state == BUY1) {
            ret = dp(i + 1, state, left);
            ret = max(ret, -v[i] + dp(i + 1, BUY2, left - 1));
            return ret;
        }
        else if (state == BUY2) {
            ret = dp(i + 1, state, left);
            ret = max(ret, -v[i] + dp(i + 1, SELL, left - 1));
            ret = max(ret, v[i] + dp(i + 1, BUY1, left - 1));
            return ret;
        }
        else {
            ret = dp(i + 1, state, left);
            ret = max(ret, v[i]  + dp(i + 1, BUY1, left - 1));
            return ret;
        }

    }

    int maxProfit(vector<int>& prices) {
        v = prices;
        n = prices.size();
        ::memset(memo, -1, sizeof memo);

        return dp(0,BUY1, 4);
    }
};

// int main() {
//     hussein();




//     return 0;
// }

