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

class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>> &edges) {
        GRAPH graph(n);
        vector<int> indegree(n);
        for (auto &edge: edges) {
            add_undirected_edge(edge[0], edge[1], graph);
            indegree[edge[0]]++;
            indegree[edge[1]]++;
        }

        queue<int> q;
        // push nodes with indegree of 1
        for (int i = 0; i < n; ++i)
            if (indegree[i] == 1)
                q.push(i);

        while (!q.empty()) {
            int sz = q.size();
            vector<int> ans;
            while (sz--) {
                int node = q.front();
                q.pop();
                ans.push_back(node);

                for (auto &ne: graph[node]) {
                    indegree[ne]--, indegree[node]--;

                    if (indegree[ne] == 1)
                        q.push(ne);
                }
            }

            if (q.empty()) return ans;
        }
        return {0};
    }
};

// int main() {


//     return 0;
// }
