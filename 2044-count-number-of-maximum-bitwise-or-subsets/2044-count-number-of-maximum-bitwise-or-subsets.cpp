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
    int n;
    int maxOr = 0;
    vector<int> cur, v;
    int ans = 0;
public:

    bool check() {
        int res = 0;
        // cout << cur << endl;
        for (auto& el : cur)
            res |= el;

        return res == maxOr;
    }

    void solve(int i) {
        if (i == n) {
            if (cur.empty())
                return;

            check() ? ++ans : ans;
            return;
        }

        cur.pb(v[i]);
        solve(i + 1);
        cur.pop_back();
        solve(i + 1);
    }

    int countMaxOrSubsets(vector<int>& nums) {
        n = nums.size();
        v = nums;
        for (auto& el : v)
            maxOr |= el;
        solve(0);

        return ans;
    }
};


// int main() {
//     hussein();

//     vector<int> v = {3,1};
//     cout << Solution().countMaxOrSubsets(v);

//     return 0;
// }
