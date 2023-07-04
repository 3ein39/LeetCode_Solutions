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
void hussein() {
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
    int memo[500 + 3];
    int n;
    int kcp;
    vector<int> v;
public:
    int dp(int i) {
        if (i >= n)
            return 0;

        auto& ret = memo[i];
        if (~ret)
            return ret;

        ret = 0;
        int cur_mx = 0, len = 0;
        for (int k = i; k < n; ++k) {
            ++len;
            cur_mx = max(cur_mx, v[k]);

            if (len > kcp)
                break;

            ret = max(ret, cur_mx * len + dp(k + 1));
        }
        return ret;
    }
    int maxSumAfterPartitioning(const vector<int>& arr, int k) {
        n = arr.size();
        v = arr;
        kcp = k;
        ::memset(memo, -1, sizeof memo);
        return dp(0);
    }
};

// int main() {
//     hussein();

//     Solution a;
//     cout << a.maxSumAfterPartitioning({1,15,7,9,2,5,10}, 3);

//     return 0;
// }
