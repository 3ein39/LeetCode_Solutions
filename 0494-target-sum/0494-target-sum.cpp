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

class Solution {
    vector<int> v;
    int target;
    int n;
    int ans = 0;
public:

    void backtrack(int idx, int sum) {
        if (idx == n) {
            if (sum == target) {
                ++ans;
            }
            return;
        }

        backtrack(idx + 1, sum + v[idx]);
        backtrack(idx + 1, sum - v[idx]);
    }

    int findTargetSumWays(vector<int>& nums, int target_) {
        n = nums.size();
        v = nums;
        target = target_;
        backtrack(0, 0);
        return ans;
    }
};

// int main() {
//     hussein();



//     return 0;
// }
