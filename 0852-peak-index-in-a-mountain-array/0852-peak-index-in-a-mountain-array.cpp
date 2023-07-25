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
    bool isPeak(vector<int>& arr, int mid) {
        if (arr[mid] > arr[mid + 1] && arr[mid] > arr[mid - 1]) return true;
        return false;
    }
    int peakIndexInMountainArray(vector<int> &arr) {
        ll l = 1, r = arr.size() - 2;

        while (l <= r) {
            ll mid = l + (r - l) / 2;
            if (isPeak(arr,mid)) return mid;
            else if (arr[mid] < arr[mid + 1]) l = mid + 1;
            else if (arr[mid - 1] > arr[mid]) r = mid - 1;
        }
        return l; // 
    }
};


