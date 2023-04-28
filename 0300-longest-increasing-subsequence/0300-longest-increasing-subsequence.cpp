#include <bits/stdc++.h>

using namespace std;

#define ll          long long
#define lp(n)       for(ll i = 0; i < (n); ++i)
#define lp1(n)      for(ll i = 1; i <= (n); ++i)
#define tc          ll testcase;   cin>>testcase;   while(testcase--)
#define all(v)      (v).begin(), (v).end()
#define allr(v)     (v).rbegin(), (v).rend()
#define fi          first
#define se          second
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

const int MAX = 2500 + 1;
ll memory[MAX][MAX];

class Solution {
public:
    int dp(vector<int>& nums, int idx, int last_idx = -1) {
        if (idx == nums.size())
            return 0;
        else {
           ll &ret = memory[idx][last_idx + 1];
            if (ret != -1)
                return ret;

            int leave = dp(nums, idx + 1, last_idx);
            int pick = 0;


            if (last_idx == -1 || nums[idx] > nums[last_idx])
                pick = 1 + dp(nums, idx + 1, idx);

            return ret = max(pick, leave);
        }

        return 0;
    }

    int lengthOfLIS(vector<int>& nums) {
        ::memset(memory, -1, sizeof memory);
        return dp(nums, 0);
    }
};
// int main() {
//     hussein();



//     return 0;
// }
