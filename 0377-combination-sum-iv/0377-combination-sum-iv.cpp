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
int n, x;
ll MOD = 1e9 + 7;
vector<int> v;
ll memo[1000 +1];
ll dp(ll rem) {
    if (rem < 0)
        return 0;
    if (rem == 0) {
        return 1;
    }

    auto& ret = memo[rem];
    if(~ret)
        return ret;

    ret = 0;
    for (int i = 0; i < n; ++i) {
        ret = ret + dp(rem - v[i]);
    }
    return ret;
}
class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        v = nums;
        n = nums.size();
            ::memset(memo, -1, sizeof memo);

        return dp(target);
    }
};
// int main() {
//     hussein();
//     cin >> n >> x;
//     v.resize(n);
//     cin >> v;
//     cout << (dp(x));
//     return 0;
// }
