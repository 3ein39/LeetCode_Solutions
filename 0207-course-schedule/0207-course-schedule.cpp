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
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites) {
        map<int, int> indegree;
        queue<int> q;
        GRAPH graph(numCourses);

        // fill in degeree map
        for (auto &el: prerequisites) {
            int u = el[0], v = el[1];
            indegree[v]++;
            add_directed_edge(u, v, graph);
        }

        for (int i = 0; i < numCourses; ++i) {
            if (!indegree.count(i))
                q.push(i);
        }

        vector<int> top;

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            top.push_back(node);

            for (auto &neighbour: graph[node]) {
                indegree[neighbour]--;

                if (indegree[neighbour] == 0) {
                    q.push(neighbour);
                }
            }
        }

        return top.size() == numCourses;


    }
};

// int main() {

//     Solution a;
//     vector<vector<int>> v{{0, 1}};
//     cout << a.canFinish(2, v);

//     return 0;
// }
