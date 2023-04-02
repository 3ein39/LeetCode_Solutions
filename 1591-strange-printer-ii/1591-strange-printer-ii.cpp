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


vector<int> topsort(const GRAPH &adjList) {	// O( E+V )
    int sz = adjList.size();
    vector<int> indegree(sz, 0);	// compute indegrees of nodes
    for (int i = 0; i < sz; ++i)
        for (int j : adjList[i])
            indegree[j]++;

    queue<int> ready;	// add all current nodes that has indegree(0)
    for (int i = 0; i < sz; ++i)
        if (!indegree[i])
            ready.push(i);

    vector<int> ordering;
    while (!ready.empty()) {	// keep picking a ready node
        int i = ready.front();
        ready.pop();
        ordering.push_back(i);

        for (int j : adjList[i])	// remove its outgoing edges
            if (--indegree[j] == 0)	// If a neighbor is ready, add it
                ready.push(j);
    }
    if (ordering.size() != adjList.size())
        ordering.clear();				//There are cycles
    return ordering;
}


class Solution {
public:
    bool isPrintable(vector<vector<int>>& targetGrid) {
        int rows = targetGrid.size(), cols = targetGrid[0].size();
        int maxColor = 60 + 1;

        // storing the 4 boundaries
        vector<int> rmax(maxColor, -1), rmin(maxColor, rows);
        vector<int> cmax(maxColor, -1), cmin(maxColor, cols);
        for (int r = 0; r < rows; ++r) {
            for (int c = 0; c < cols; ++c) {
                int color = targetGrid[r][c];
                rmax[color] = max(rmax[color], r);
                rmin[color] = min(rmin[color], r);
                cmax[color] = max(cmax[color], c);
                cmin[color] = min(cmin[color], c);
            }
        }

        GRAPH graph(maxColor);
        for (int color = 0; color < maxColor; ++color) {
            for (int r = rmin[color]; r <= rmax[color]; ++r) {
                for (int c = cmin[color]; c <= cmax[color]; ++c) {
                    if (targetGrid[r][c] != color)
                        add_directed_edge(color, targetGrid[r][c], graph);
                }
            }
        }
        
        return topsort(graph).size() > 0;

    }
};

// int main() {


//     return 0;
// }

