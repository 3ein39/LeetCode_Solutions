#include<bits/stdc++.h>

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


#define GRAPH vector<vector<int>>

//void add_undirected_edge(int from, int to, GRAPH &graph) {
//    graph[from].pb({to, true});
//    graph[to].pb({from, false});
//}

class Solution {
    int n, m;
    bool valid = false;
public:
    bool is_valid(int i, int j) {
        if (i < 0 || i >= n || j < 0 || j >= m) return false;

        return true;
    }

    void dfs(GRAPH &graph, int i, int j, int k, vector<vector<bool>> &vis) {
        if (!is_valid(i, j) || vis[i][j])
            return;

        vis[i][j] = true;

        if (i == n - 1 && j == m - 1) valid = true;

        for (int d = 0; d < 4; d++) {
            int ni = i + dx[d], nj = j + dy[d];
            if (is_valid(ni, nj) && abs(graph[i][j] - graph[ni][nj]) <= k)
                dfs(graph, ni, nj, k, vis);
        }

    }

    int minimumEffortPath(vector<vector<int>> &heights) {
        n = heights.size(), m = heights[0].size();

        int l = 0, r = 1e7, ans = -1;

        while (l <= r) {
            ll mid = l + (r - l) / 2;
            vector<vector<bool>> vis(n, vector<bool>(m, false));
            valid = false;

            dfs(heights, 0, 0, mid, vis);

            if (valid)
                ans = mid, r = mid - 1;
            else
                l = mid + 1;
        }

        return ans;
    }
};