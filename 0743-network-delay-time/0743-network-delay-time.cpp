#include <bits/stdc++.h>

using namespace std;

#define ll          long long
#define lp(n)       for(ll i = 0; i < (n); ++i)
#define lp1(n)      for(ll i = 1; i <= (n); ++i)
#define tc          ll testcase;   cin>>testcase;   while(testcase--)
#define all(v)      (v).begin(), (v).end()
#define watch(num)  cout<< #num <<": "<< num << "\n";
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

void hussein() {
    improve;
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
}

class Solution {
    struct edge {
        int to, cost;
    };
    int ans = 0;
public:
    void dijkstra(vector<vector<edge>>& graph, vector<int>& dist, int src, vector<bool>& vis) {
        dist[src] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, src});
        while (!pq.empty()) {
            auto cur = pq.top();
            pq.pop();
            if (vis[cur.second])
                continue;
            vis[cur.second] = true;
            for (auto& el : graph[cur.second]) {
                if (dist[el.to] > dist[cur.second] + el.cost) {
                    dist[el.to] = dist[cur.second] + el.cost;
                    pq.push({dist[el.to], el.to});
                }
            }
        }
    }

    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<edge>> graph(n + 1);
        for (auto& el : times) {
            graph[el[0]].push_back({el[1], el[2]});
        }

        vector<bool> vis(n + 1, false);
        vector<int> dist(n + 1, OO);
        dijkstra(graph, dist, k, vis);
        

        if (any_of(dist.begin() + 1, dist.end(), [](int x) { return x == OO; }))
            return -1;
        return *max_element(dist.begin() + 1, dist.end());
    }
};

// int main() {
//     hussein();



//     return 0;
// }


