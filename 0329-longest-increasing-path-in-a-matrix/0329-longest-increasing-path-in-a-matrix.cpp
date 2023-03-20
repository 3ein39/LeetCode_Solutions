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


//void add_undirected_edge(int from, int to, GRAPH &graph) {
//    graph[from].pb(to);
//    graph[to].pb(from);
//}


void hussein() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    improve;
}


class Solution {
    int n, m;


    bool valid(int i, int j) {
        if (i < 0 || j < 0 || i >= n || j >= m)
            return false;
        return true;
    };

    void add_directed_edge(int from, int to, GRAPH &graph) {
        graph[from].push_back(to);
    };

public:
    int longestIncreasingPath(vector<vector<int>> &matrix) {
        n = matrix.size(), m = matrix[0].size();

        vector<vector<int>> indegree(n, vector<int>(m, 0));


        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                for (int d = 0; d < 4; ++d) {
                    int ni = i + dx[d], nj = j + dy[d];

                    if (valid(ni, nj) && matrix[ni][nj] < matrix[i][j]) {
                        indegree[i][j]++;
                    }
                }
            }
        }

        // create a queue and push nodes of indegree of 0;
        queue<pair<int, int>> q;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (indegree[i][j] == 0)
                    q.push({i, j});
            }
        }

        ll path = 0;
        while (!q.empty()) {
            int sz = q.size();

            while (sz--) {
                auto node = q.front();
                q.pop();

                for (int d = 0; d < 4; ++d) {
                    int ni = node.first + dx[d], nj = node.second + dy[d];

                    // loop on negbours if valid decrease indegree and push
                    if (valid(ni, nj) && matrix[ni][nj] > matrix[node.first][node.second]) {
                        indegree[ni][nj]--;

                        if (indegree[ni][nj] == 0)
                            q.push({ni, nj});
                    }
                }
            }
            ++path;
        }

        return path;

    }
};

// int main() {

//     Solution a;
//     vector<vector<int>> mat = {{9, 9, 4},
//                                {6, 6, 8},
//                                {2, 1, 1}};

//     cout << a.longestIncreasingPath(mat);
//     return 0;
// }
