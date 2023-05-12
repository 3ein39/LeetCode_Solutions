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
const int OO = 1000 + 1;

/* 3ein39
                    " وَأَن لَّيْسَ لِلْإِنسَانِ إِلَّا مَا سَعَى ﴿39﴾ وَأَنَّ سَعْيَهُ سَوْفَ يُرَى ﴿40﴾ ثُمَّ يُجْزَاهُ الْجَزَاء الْأَوْفَى "
                                      My way to My dream....
*/

void hussein() {
    improve;
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
}
ll memory[OO][OO];
class Solution {
    int n, m;
    string s1, s2;
public:
    ll lcs(int idx1, int idx2) {
        if (n == idx1 || m == idx2)
            return 0;

        auto& ret = memory[idx1][idx2];
        if (ret != -1)
            return ret;

        if (s1[idx1] == s2[idx2])
            return ret = 1 + lcs(idx1 + 1, idx2 + 1);

        return ret = max(lcs(idx1 + 1, idx2), lcs(idx1, idx2 + 1));
    }

    int longestCommonSubsequence(string text1, string text2) {
        n = text1.size(), m = text2.size();
        s1 = text1, s2 = text2;
        ::memset(memory, -1, sizeof memory);
        return lcs(0, 0);
    }
};
// int main() {
//     hussein();


//     return 0;

// }
