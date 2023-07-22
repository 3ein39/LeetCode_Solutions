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
#define watch(num)  cout<< #num <<": "<< num << "\n";
#define pb          push_back
#define yes         cout<<"YES"<<endl
#define no          cout<<"NO"<<endl
#define improve     ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ull         unsigned long long
#define Node        ListNode
int dx4[4]{-1, 0, 1, 0};
int dy4[4]{0, 1, 0, -1};
int dx8[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dy8[8] = {0, 1, 1, 1, 0, -1, -1, -1};
#define endl        '\n';

// knight
int kdx[8] {1,1,-1,-1,2,2,-2,-2};
int kdy[8] {2,-2,2,-2,1,-1,1,-1};


template<typename T>
istream &operator>>(istream &input, vector<T> &data) {
    for (T &x: data)input >> x;
    return input;
}

template<typename T>
ostream &operator<<(ostream &output, const vector<T> &data) {
    for (const T &x: data)output << x << " ";
    return output;
}



#define GRAPH vector<vector<int>>


void add_undirected_edge(int from, int to, GRAPH &graph) {
    graph[from].pb(to);
    graph[to].pb(from);
}

void add_directed_edge(int from, int to, GRAPH &graph) {
    graph[from].pb(to);
}
void hussein() {
    improve;
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
}


class Solution {
        bool flag;
        vector<bool> vis;
public:
    void dfs(int node, int start, int destination,vector<vector<int>>& graph) {
        if (node == destination) {
            flag = true;
            return;
        }
        
        if (vis[node])
            return;
        
        vis[node] = 1;

        for (auto& ne : graph[node]) {
            if (ne == start) continue;
            dfs(ne, start, destination, graph);
        }
    }

    bool validPath(int n, const vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> graph(n);
        for (auto& v: edges) {
            add_undirected_edge(v[0], v[1], graph);
        }
        vis.resize(n, false);
        dfs(source, source, destination, graph);

        return flag;
    }
};

// int main() {
//     hussein();

//     cout << Solution().validPath(3, {{0,1},{1,2},{2,0}}, 0, 2);

//     return 0;
// }
