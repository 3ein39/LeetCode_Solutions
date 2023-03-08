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


struct node {
    int x, color;// 0 for red, 1 for blue
};

void add_undirected_edge(int from, int to, GRAPH &graph, int color) {
    graph[from].pb({to, color});
    graph[to].pb({from, color});
}

void add_directed_edge(int from, int to, GRAPH &graph, int color) {
    graph[from].pb({to, color});
}

void hussein() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    improve;
}

class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>> &redEdges, vector<vector<int>> &blueEdges) {
        vector<int> answer(n, -1);
        vector<vector<int>> vis(n, vector<int>(2, OO));

        GRAPH g(n);

        for (auto &el: redEdges) {
            int u = el[0], v = el[1];

            add_directed_edge(u, v, g, 0);
        }

        for (auto &el: blueEdges) {
            int u = el[0], v = el[1];

            add_directed_edge(u, v, g, 1);
        }

        vis[0][0] = vis[0][1] = true;
        answer[0] = 0;
        int length = 1;

        queue<node> q;
        q.push({0, 0});
        q.push({0, 1});

        while (!q.empty()) {
            int sz = q.size();

            while (sz--) {
                node n = q.front();
                q.pop();

                for (auto &ne: g[n.x]) {
                    if (vis[ne.x][ne.color] == OO && ne.color != n.color) {
                        q.push(ne);
                        vis[ne.x][ne.color] = length;

                        if (answer[ne.x] == -1)
                            answer[ne.x] = length;
                    }
                }
            }
            length++;
        }

        return answer;
    }
};

//    int main() {
//    hussein();
//
//    vector<vector<int>> v = {{1, 2, 2, 3, 5},
//                             {3, 2, 3, 4, 4},
//                             {2, 4, 5, 3, 1},
//                             {6, 7, 1, 4, 5},
//                             {5, 1, 1, 2, 4}};
//
//    Solution a;
//    a.pacificAtlantic(v);
//
//    return 0;
//}
