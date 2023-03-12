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


#define GRAPH vector<vector<node>>

//
//void add_undirected_edge(int from, int to, GRAPH &graph, int color) {
//    graph[from].pb({to, color});
//    graph[to].pb({from, color});
//}
//
//void add_directed_edge(int from, int to, GRAPH &graph, int color) {
//    graph[from].pb({to, color});
//}

void hussein() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    improve;
}

struct cell {
    int binary_value;
    int length;
};

int n, m;

bool valid(int i, int j) {
    if (i < 0 || j < 0 || i >= n || j >= m)
        return false;

    return true;
}

class Solution {
    queue<vector<int>> q;

    void dfs(int i, int j, vector<vector<int>> &grid, int oldcolor = 1, int newcolor = 2) {
        grid[i][j] = newcolor;
        q.push({i, j});

        for (int k = 0; k < 4; ++k) {
            int ni = i + dx[k], nj = j + dy[k];

            if (!valid(ni, nj) || grid[ni][nj] != oldcolor)
                continue;
            dfs(ni, nj, grid, oldcolor, newcolor);
        }
    }

public:
    int shortestBridge(vector<vector<int>> &grid) {
        n = grid.size(), m = grid[0].size();
        for (int i = 0; i < n && q.empty(); ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == 1) {
                    dfs(i, j, grid);
                    break;
                }
            }
        }

        int level = 0;
        while (!q.empty()) {
            int sz = q.size();

            while (sz--) {
                int i = q.front()[0], j = q.front()[1];
                q.pop();

                for (int k = 0; k < 4; ++k) {
                    int ni = i + dx[k], nj = j + dy[k];

                    if (!valid(ni, nj) || grid[ni][nj] == 2 || grid[ni][nj] == 3)
                        continue;

                    if (grid[ni][nj] == 1) // bridged
                        return level;

                    q.push({ni, nj});
                    grid[ni][nj] = 3;
                }
            }
            ++level;
        }

        return 1;
    }
};

// int main() {
//     vector<vector<int>> mat = {{0, 0, 1, 0, 1},
//                                {0, 1, 1, 0, 1},
//                                {0, 1, 0, 0, 1},
//                                {0, 0, 0, 0, 0},
//                                {0, 0, 0, 0, 0}};
//     Solution a;

//     int ans = a.shortestBridge(mat);
//     cout << ans;
// }
