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
    map<int, bool> memo;
public:
    bool solve(vector<int>& nums, int idx) {
        // if(idx == -1) return false;
        // if (idx == 0) return true;
        
        if (memo.count(idx))
            return memo[idx];
        
        auto& ret = memo[idx];
        ret = false;

        if (idx > 0 && nums[idx] == nums[idx - 1])
            ret |= solve(nums, idx - 2);

        if (idx > 1 && nums[idx] == nums[idx - 1] && nums[idx - 1] == nums[idx - 2])
            ret |= solve(nums, idx - 3);

        if (idx > 1 && nums[idx] == nums[idx - 1] + 1 && nums[idx - 1]  == nums[idx - 2] + 1)
            ret |= solve(nums, idx - 3);
        return ret;
    }

    bool validPartition(vector<int>& nums) {
        // for (int i = 0; i < nums.size(); ++i)
            // memo[i] = 0;
        memo[-1] = true;
        return solve(nums, nums.size() - 1);
    }
};
// int main() {
//     hussein();



//     return 0;
// }
