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
    // priority queue
    int minimumOperations(vector<int> &nums) {
        priority_queue<int, vector<int>, greater<int>> mn_heap;

        for (auto &el: nums)
            mn_heap.push(el);

        int cur_min = 0;

        int ans = 0;
        while (!mn_heap.empty()) {
            if (mn_heap.top() == 0) mn_heap.pop();
            else {
                int top = mn_heap.top() - cur_min;
                if (top != 0) {
                    cur_min += top;
                    ++ans;
                }
                mn_heap.pop();
            }
        }

        return ans;
    }
};
