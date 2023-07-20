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
public:
    vector<vector<int>> ans;
vector<vector<int>> g;
int n;
vector<int> path;
    void solve(int node) {
        if (node == n - 1){
            ans.push_back(path);
            return;
        }

        for (auto& ne : g[node]) {
            path.pb(ne);
            solve(ne);
            path.pop_back();
        }

    }

    vector<vector<int>> allPathsSourceTarget(const vector<vector<int>>& graph) {
        g = graph;
        n = g.size();
        path.pb(0);
        solve(0);
        return ans;
    }
};

// int main() {
//      hussein();

//     Solution().allPathsSourceTarget({{0,1,3},{0,2,3},{0,0,4},{0,0,3,4},{0,0,1,3,4},{0,0,1,2,3,4},{0,0,1,4}});

//      return 0;
//  }
