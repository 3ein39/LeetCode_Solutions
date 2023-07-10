#include <bits/stdc++.h>
using namespace std;
#define ll          long long
#define lp(n)       for(ll i = 0; i < (n); ++i)
#define lp1(n)      for(ll i = 1; i <= (n); ++i)
#define tc          ll testcase;   cin>>testcase;   while(testcase--)
#define all(v)      (v).begin(), (v).end()
#define allr(v)     (v).rbegin(), (v).rend()
#define pb          push_back
#define watch(num)  cout<< #num <<": "<< num << "\n";
#define yes         cout<<"YES"<<endl
#define no          cout<<"NO"<<endl
#define improve     ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
int dx[4]{-1, 0, 1, 0};
int dy[4]{0, 1, 0, -1};
void hussien() {
    improve;
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
}

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

/* 3ein39
                    " وَأَن لَّيْسَ لِلْإِنسَانِ إِلَّا مَا سَعَى ﴿39﴾ وَأَنَّ سَعْيَهُ سَوْفَ يُرَى ﴿40﴾ ثُمَّ يُجْزَاهُ الْجَزَاء الْأَوْفَى "
                                      My way to My dream....
*/

class Solution {
    int r, c;
    ll memo[55][55][55];
    ll MOD = 1e9 + 7;
public:
    ll add (ll a, ll b) {
        return (a% MOD + b % MOD) % MOD;
    }
    
    bool valid(int i, int j) {
        if (i < 0 || j < 0 || i >= r || j >= c)
            return false;
        return true;
    }

    ll dp(int i, int j, int rem) {
        if (!valid(i, j))
            return 1;
        if (!rem)
            return 0;

        auto& ret = memo[i][j][rem];
        if (~ret)
            return ret;

        ret = 0;
        for (int k = 0; k < 4; ++k) {
            int ni = i + dx[k], nj = j + dy[k];
            ret = add(ret,dp(ni,nj,rem-1));
        }
        return ret % MOD;
    }

    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        r = m, c = n;
                ::memset(memo, -1, sizeof memo);

        return dp(startRow,startColumn, maxMove);
    }
};

// int main() {
//     hussien();

//     return 0;
// }
