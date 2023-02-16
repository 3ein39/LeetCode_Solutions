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
    int get_min(vector<int>& v, int n) {
        for (auto & el: v) {
            if (el > 0)
                return el;
        }
        
        return -1;
    }
    
    int minimumOperations(vector<int> &nums) {
        int n = nums.size();

        sort(all(nums));
        ll ans {0};
        while (true) {
            int mn = get_min(nums, n);
            
            if (mn == -1) return ans;
            
            for (auto& el : nums) {
                if (el > 0)
                    el -= mn;
            }
            ++ans;
        }
        return ans;
    }
};
