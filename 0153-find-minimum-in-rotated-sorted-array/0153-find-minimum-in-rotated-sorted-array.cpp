#include<bits/stdc++.h>

using namespace std;

#define ll          long long
#define lp(n)       for(ll i = 0; i < (n); ++i)
#define lp1(n)      for(ll i = 1; i <= (n); ++i)
#define tc          ll testcase;   cin>>testcase;   while(testcase--)
#define all(v)      (v).begin(), (v).end()
#define fi          first
#define se          second
#define pb          push_back
#define yes         cout<<"YES"<<endl
#define no          cout<<"NO"<<endl
#define Node        ListNode

/* 3ein39
                    " وَأَن لَّيْسَ لِلْإِنسَانِ إِلَّا مَا سَعَى ﴿39﴾ وَأَنَّ سَعْيَهُ سَوْفَ يُرَى ﴿40﴾ ثُمَّ يُجْزَاهُ الْجَزَاء الْأَوْفَى "
                                      My way to My dream....
*/


class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0, r = nums.size() - 1, ans = 0;
        while (l <= r) {
            int mid = l + (r - l) / 2;

            if (nums[mid] < nums[ans]) {
                ans = mid;
                r = mid - 1;
            } else 
                l = mid + 1;
        }
        return nums[ans];
    }
};
