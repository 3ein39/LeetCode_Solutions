#include <bits/stdc++.h>

using namespace std;

#define ull         unsigned long long
#define ll          long long
#define lp(n)       for(ll i = 0; i < (n); ++i)
#define lp1(n)      for(ll i = 1; i <= (n); ++i)
#define tc          ll testcase;   cin>>testcase;   while(testcase--)
#define all(v)      (v).begin(), (v).end()
#define watch(num)  cout<< #num <<": "<< num << "\n";
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
const int OO = 10000000;


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
    map<pair<int, int>, bool> memo;
    int n;
    vector<int> v;
public:

    bool dp (int i, int k) {
        if (i == n-1) {
            return true;
        }
        if (i >= n)
            return false;

        if (memo.contains({i, k}))
            return memo[{i, k}];

        // choices for first idx
        bool ret = false;
        if (i == 0) {
            if (v[i + 1] == 1)
                ret |= dp(i + 1, k + 1);
            return memo[{i, k}] = ret;
        }

        for (int jump = -1; jump < 2; ++jump) {
            int nextJump = jump+ k;
            if (jump + k <= 0) continue;

            if (binary_search(all(v), v[i] + nextJump)) {
                auto pos = lower_bound(all(v), v[i] + nextJump) - v.begin();
                ret |= dp(pos, k + jump);
            }
        }


        return memo[{i, k}] = ret;
    }

    bool canCross(const vector<int>& stones) {
     n = stones.size();
        v = stones;

        return dp(0, 0);
    }
};
// int main() {
//     hussein();

//     auto ans =  Solution().canCross({0,1,3,5,6,8,12,17});
//     cout << ans;

//     return 0;
// }
