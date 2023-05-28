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
int memo[1000];
class Solution {
    vector<int> v;
    int n;
public:
    int dp(int i) {
        if (i == n)
            return 0;
        
        auto& ret = memo[i];
        if (~ret)
            return ret;
        
        int ch1 = v[i] + dp(i + 1);
        int ch2 = 1e9;
        
        if (i + 2 <= n)
            ch2 = v[i] + dp(i + 2);
        
        return ret = min(ch1, ch2);
    }
    
    int minCostClimbingStairs(vector<int>& cost) {
        memset(memo, -1, sizeof memo);
        n = cost.size();
        v = cost;
        
        return min(dp(0), dp(1));
        
    }
};

// int main() {
//     hussein();

//     return 0;
// }

