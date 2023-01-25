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

/* 3ein39
                    " وَأَن لَّيْسَ لِلْإِنسَانِ إِلَّا مَا سَعَى ﴿39﴾ وَأَنَّ سَعْيَهُ سَوْفَ يُرَى ﴿40﴾ ثُمَّ يُجْزَاهُ الْجَزَاء الْأَوْفَى "
                                      My way to My dream....
*/

class Solution {
public:
    vector<int> twoSum(vector<int> &nums, int target) {
        vector<pair<int, int>> v(nums.size());
        for (int i = 0; i < nums.size(); ++i) {
            v[i] = {i, nums[i]};
        }

        sort(all(v), [](pair<int, int>& a, pair<int, int>& b) {
            return a.second < b.second;
        });
        
        int l = 0, r = nums.size() - 1;
//        sort(nums.begin(), nums.end());
        while (l != r) {
            if (v[l].second + v[r].second == target) return {v[l].first, v[r].first};

            if (v[l].second + v[r].second > target)
                --r;
            else
                ++l;
        }
        return {-1};
    }
};