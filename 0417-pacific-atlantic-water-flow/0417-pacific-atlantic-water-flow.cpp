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
const int OO = 10000000;

/* 3ein39
                    " وَأَن لَّيْسَ لِلْإِنسَانِ إِلَّا مَا سَعَى ﴿39﴾ وَأَنَّ سَعْيَهُ سَوْفَ يُرَى ﴿40﴾ ثُمَّ يُجْزَاهُ الْجَزَاء الْأَوْفَى "
                                      My way to My dream....
*/


#define GRAPH vector<vector<int>>

void add_undirected_edge(int from, int to, GRAPH &graph) {
    graph[from].pb(to);
    graph[to].pb(from);
}

void add_directed_edge(int from, int to, GRAPH &graph) {
    graph[from].pb(to);
}

void hussein() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    improve;
}

struct cell {
    int r, c;
};

bool isvalid(int i, int j, int n, int m) {
    if (i < 0 || i >= n || j < 0 || j >= m)
        return false;
    return true;
}

class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>> &heights) {
        int n = heights.size(), m = heights[0].size();

        vector<vector<bool>> vis(n, vector<bool>(m, false));
        vector<vector<int>> freq(n, vector<int>(m, 0));
        vector<vector<int>> ans;

        queue<cell> q;
        // push pacific nodes
        for (int j = 0; j < m; ++j) {
            q.push({0, j});
            vis[0][j] = true;
            freq[0][j]++;
        }
        for (int i = 1; i < n; ++i) {
            q.push({i, 0});
            vis[i][0] = true;
            freq[i][0]++;
        }

        while (!q.empty()) {
            int sz = q.size();

            while (sz--) {
                int noder = q.front().r, nodec = q.front().c;
                q.pop();

//                vis[noder][nodec] = true;
//                freq[noder][nodec]++;

                for (int i = 0; i < 4; ++i) {
                    int nr = noder + dx[i], nc = nodec + dy[i];

                    if (isvalid(nr, nc, n, m) && !vis[nr][nc] && heights[nr][nc] >= heights[noder][nodec]) {
                        q.push({nr, nc});
                        vis[nr][nc] = true;
                        freq[nr][nc]++;
                    }
                }
            }
        }

        // make new vis then push atlantic cells

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                vis[i][j] = false;
            }
        }

        // push atlantic nodes
        for (int j = 0; j < m; ++j) {
            q.push({n - 1, j});
            vis[n -1][j] = true;
            freq[n-1][j]++;
        }
        for (int i = 0; i < n - 1; ++i) {
            q.push({i, m - 1});
            vis[i][m - 1] = true;
            freq[i][m - 1]++;
        }

        while (!q.empty()) {
            int sz = q.size();

            while (sz--) {
                int noder = q.front().r, nodec = q.front().c;
                q.pop();

                // vis[noder][nodec] = true;
                // freq[noder][nodec]++;

                for (int i = 0; i < 4; ++i) {
                    int nr = noder + dx[i], nc = nodec + dy[i];

                    if (isvalid(nr, nc, n, m) && !vis[nr][nc] && heights[nr][nc] >= heights[noder][nodec]) {
                        q.push({nr, nc});
                          vis[nr][nc] = true;
                        freq[nr][nc]++;
                    }
                }
            }
        }

        // checking valid cells
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (freq[i][j] == 2) {
                    vector<int> v = {i, j};
                    ans.push_back(v);
                }
            }
        }

        return ans;
    }
};

// int main() {
//     hussein();

//     vector<vector<int>> v = {{1, 2, 2, 3, 5},
//                              {3, 2, 3, 4, 4},
//                              {2, 4, 5, 3, 1},
//                              {6, 7, 1, 4, 5},
//                              {5, 1, 1, 2, 4}};

//     Solution a;
//     a.pacificAtlantic(v);

//     return 0;
// }
