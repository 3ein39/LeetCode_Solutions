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
#define watch(num)  cout<< #num <<": "<< num << "\n";
int dx[4]{-1, 0, 1, 0};
int dy[4]{0, 1, 0, -1};
int dx8[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dy8[8] = {0, 1, 1, 1, 0, -1, -1, -1};
#define endl        '\n';

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
    vector<vector<string>> ans;
    vector<string> path;
    int n;
    bool col[10], sum[20], diff[100];
public:
    void solve(int r) {
        if (r == n) {
            ans.push_back(path);
            return ;
        }

        for (int c = 0; c < n; ++c) {
            if (col[c] || sum[r + c] || diff[r - c + 10]) continue;
            path[r][c] = 'Q';
            col[c] = true;
            sum[r + c] = true;
            diff[r - c + 10] = true;

            solve(r + 1);

            diff[r - c + 10] = false;
            sum[r + c] = false;
            col[c] = false;
            path[r][c] = '.';
        }
    }

    vector<vector<string>> solveNQueens(int n_) {
        n = n_;
        path.resize(n, string(n, '.'));
        
        ::memset(col, 0, sizeof col);
        ::memset(diff, 0, sizeof diff);
        ::memset(sum, 0, sizeof sum);
        solve(0);
        return ans;
    }
};