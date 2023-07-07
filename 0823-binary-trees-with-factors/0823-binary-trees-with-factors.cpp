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
ll n;
unordered_set<ll> values;
unordered_map<ll, ll> memo;
ll MOD = 1e9 + 7;
ll add(ll a, ll b) {
    return (a% MOD + b% MOD)% MOD;
}

ll dp(int root) {
    if (memo.count(root))
        return memo[root];

    memo[root] = 1;
    for (auto x : values) {
       if (values.count(root / x) && (root % x == 0))
           memo[root] = add(memo[root] , dp(x)*dp(root / x));
    }
    return memo[root] % MOD;
}

class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        ll ans = 0;
        memo.clear();
		values.clear();
        for (auto& el : arr)
            values.insert(el);

        for (int i = 0; i < arr.size(); ++i) {
            ans = add(ans, dp(arr[i]));
        }
        return ans % MOD;
    }
};

// int main() {
//     hussien();

//     Solution a;
//     vector<int> vv = {15,13,22,7,11};
//     cout << a.numFactoredBinaryTrees(vv);

//     return 0;
// }
