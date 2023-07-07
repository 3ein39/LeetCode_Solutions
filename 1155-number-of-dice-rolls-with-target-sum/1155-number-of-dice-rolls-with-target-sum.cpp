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
ll memo[30 + 1][1000 + 1];
ll MOD = 1e9 + 7;
ll sz, faces;


ll add(ll a, ll b) {
    return (a % MOD + b % MOD) % MOD;
}

class Solution {
public:
    ll dp(int i, ll rem) {
        if (i >= sz && rem == 0)
            return 1;
        if (i >= sz || rem < 0)
            return 0;

        auto& ret = memo[i][rem];
        if (~ret)
            return ret;

        ret = 0;
        for (int j = 1; j <= faces; ++j) {
            ret = add(ret, dp(i + 1, rem - j));
        }

        return ret;
    }

    int numRollsToTarget(int n, int k, int target) {
        sz = n;
        faces = k;
        ::memset(memo, -1, sizeof memo);
        return dp(0, target);
    }
};

// int main() {
//     hussien();

//     Solution a;
//     cout << a.numRollsToTarget(30, 30, 500);

//     return 0;
// }
