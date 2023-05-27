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


const int OO = 1000 + 1;
int LIS[OO];
int LDS[OO];
class Solution {
    int n;
    vector<int> v;
public:

    int lds(int cur) {
        if (cur == n)
            return 0;

        auto& ret = LDS[cur];
        if (~ret)
            return ret;

        ret = 0;
        for (int next = cur + 1; next < n; ++next) {
            if (v[next] < v[cur])
                ret = max(ret, lds(next));
        }

        ret += 1;
        return ret;
    }
    int lis(int cur) {
        if (cur == -1)
            return 0;

        auto& ret = LIS[cur];
        if (~ret)
            return ret;

        ret = 0;
        for (int prev = cur - 1; prev >= 0; --prev) {
            if (v[cur] > v[prev])
                ret = max(ret, lis(prev));
        }

        ret += 1;
        return ret;
    }

    int minimumMountainRemovals(vector<int>& nums) {
        n = nums.size();
        v = nums;

        memset(LIS, -1, sizeof LIS);
        memset(LDS, -1, sizeof LDS);

        int ans = 0;
        for (int i = 0; i < n; ++i) {
            if (lis(i) == 1 || lds(i) == 1)
                continue;

            int cur = lis(i) + lds(i) - 1;
            ans = max(cur, ans);
        }
        return n - ans;
    }
};
// int main() {
//     hussein();



//     return 0;
// }

