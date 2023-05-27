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
const int OO = 501;
int memory[OO][OO];
class Solution {
public:
    int n, m;
    string s1 ,s2;
    int minDistance(const string word1,const string word2) {
        ::memset(memory, -1, sizeof memory);
        n = word1.size(), m = word2.size();
        s1 = word1, s2 = word2;

        return dp(0, 0);
    }

    int dp(int i, int j) {
        if (i == n && j == m)
            return 0;

        if (i == n)
            return m - j;

        if (j == m)
            return n - i;

        auto& ret = memory[i][j];
        if (~ret)
            return ret;

        if (s1[i] == s2[j])
            return dp(i + 1, j + 1);

        int insert, delt, replace;
        insert = 1 + dp(i, j + 1);
        delt = 1 + dp(i + 1, j);
        replace = 1 + dp(i + 1, j + 1);

        return ret = min({insert, delt, replace});
    }
};

// int main() {
//     hussein();

// Solution a;
//     cout << a.minDistance("intention", "execution");

//     return 0;
// }

