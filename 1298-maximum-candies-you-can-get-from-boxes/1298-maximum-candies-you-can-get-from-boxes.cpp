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
    ll ans = 0;

    void addKeysFromBoxes(vector<int> &status, vector<vector<int>> &keys, vector<int> &boxes) {
        for (auto &box: boxes) {
            for (auto &key: keys[box]) {
                status[key] = 1;
            }
        }
    }

    void openBoxes(queue<int> &q, vector<bool> &vis, vector<int> &hasKey, vector<int> &candies, vector<int> &boxes) {
        for (auto &box: boxes) {
            if (!vis[box] && hasKey[box]) {
                q.push(box);
                vis[box] = true;
                ans += candies[box];
            }
        }
    }

public:
    int maxCandies(vector<int> &status, vector<int> &candies, vector<vector<int>> &keys,
                   vector<vector<int>> &containedBoxes, vector<int> &initialBoxes) {

        queue<int> q;
        vector<bool> vis(status.size(), false);
        addKeysFromBoxes(status, keys, initialBoxes);
        openBoxes(q, vis, status, candies, initialBoxes);

        while (!q.empty()) {
            int box = q.front();
            q.pop();

            addKeysFromBoxes(status, keys, containedBoxes[box]);
            openBoxes(q, vis, status, candies, containedBoxes[box]);

        }
        return ans;
    }
};

// int main() {
//     return 0;
// }
