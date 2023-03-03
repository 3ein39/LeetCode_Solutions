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


#define GRAPH vector<vector<char>>

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

int n, m;

bool isvalid(int i, int j) {
    if (i < 0 || i >= n || j < 0 || j >= m)
        return false;

    return true;
}

//void dfs(int i, int j, GRAPH &g, vector<vector<bool>> &vis, char color, int pari = -1, int parj = -1) {
//    if (!isvalid(i, j) || g[i][j] != color || found)
//        return;
//
//    if (vis[i][j]) {
//        found = true;
//
//        return;
//    }
//
//
//    vis[i][j] = true;
//
//    for (int k = 0; k < 4; ++k) {
//        int ni = i + dx[k], nj = j + dy[k];
//        if (pari == ni && parj == nj)
//            continue;
//
//        dfs(ni, nj, g, vis, color, i, j);
//    }
//}
//

class Solution {
public:

    bool canReach(vector<int> &arr, int start) {
        vector<bool> vis(arr.size(), 0);

        queue<int> q;
        q.push(start);
        vis[start] = true;
        while (!q.empty()) {
            int sz = q.size();

            while (sz--) {
                int idx = q.front();
                vis[idx] = true;
                q.pop();

                if (arr[idx] == 0)
                    return true;

                if (idx + arr[idx] < arr.size() && !vis[idx + arr[idx]])
                    q.push(idx + arr[idx]);

                if (idx - arr[idx] >= 0 && !vis[idx - arr[idx]])
                    q.push(idx - arr[idx]);
            }
        }

        return false;
    }
};

// int main() {
//     hussein();


//     return 0;
// }
