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

void fill(pair<int, int> &jugs, int jug1, int jug2, queue<pair<int, int>> &q,
          map<pair<int, int>, bool> &vis) {

    if (jug1 > jug2) // optimization
        swap(jug1, jug2);

    if (!vis.count({jug1, jug2})) {
        vis[{jug1, jug2}] = true;
        q.push({jug1, jug2});
    }
}

class Solution {
public:
    bool canMeasureWater(int jug1Capacity, int jug2Capacity, int targetCapacity) {
        pair<int, int> jugs{0, 0};

        map<pair<int, int>, bool> vis;
        queue<pair<int, int>> q;

        q.push({0, 0});
        vis[{0, 0}] = true;

        if (jug1Capacity + jug2Capacity == targetCapacity)
            return true;

        if (jug2Capacity + jug1Capacity < targetCapacity)
            return false;

        while (!q.empty()) {
            int sz = q.size();

            while (sz--) {
                auto node = q.front();
                q.pop();

                if (node.first + node.second == targetCapacity)
                    return true;

                int mn1 = min(node.first, jug2Capacity - node.second), mn2 = min(node.second,
                                                                                 jug1Capacity - node.first);
                // try the 6 operations
                fill(node, 0, node.second, q, vis); // empty 1
                fill(node, node.first, 0, q, vis); // empty 2

                fill(node, jug1Capacity, node.second, q, vis); // fill 1
                fill(node, node.first, jug2Capacity, q, vis); // fill 2

                fill(node, node.first - mn1, node.second + mn1, q, vis); // fill 2
                fill(node, node.first + mn2, node.second - mn2, q, vis); // fill 2
            }
        }
        return false;
    }
};

// int main() {

//     tc {
//         int jug1, jug2, target;
//         cin >> jug1 >> jug2 >> target;

//         Solution a;
//         cout << a.canMeasureWater(jug1, jug2, target) << endl;
//     }

//     return 0;
// }
