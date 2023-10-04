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

void hussein() {
  improve;
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif
}


#define GRAPH vector<vector<edge>>

//void add_undirected_edge(int from, int to, GRAPH &graph) {
//    graph[from].pb(to);
//    graph[to].pb(from);
//}

//void add_directed_edge(int from, edge e, GRAPH &graph) {
//  graph[from].pb(e);
//}

class Solution {
public:
	 struct edge {
	   int to, cost;
	   edge(int to_, int cost_)
	   {
		 to = to_;
		 cost = cost_;
	   }
	 };

     void add_undir_e(int from, edge e, GRAPH& graph) {
	   graph[from].pb(e);
	   graph[e.to].pb({from, e.cost});
     }

     vector<int> dijkstra(int src, GRAPH& graph) {
	   vector<int> dist(graph.size(), INT_MAX);
	   dist[src] = 0;
	   priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	   pq.push({0, src});
	   while (!pq.empty()) {
		 auto top = pq.top();
	     pq.pop();
	     int u = top.second, d = top.first;
	     if (d > dist[u])continue;
	     for (auto& e : graph[u]) {
		   if (dist[u] + e.cost < dist[e.to]) {
			 dist[e.to] = dist[u] + e.cost;
			 pq.push({dist[e.to], e.to});
		   }
	     }
	   }
	   return dist;
     }

    int countRestrictedPaths(int n, vector<vector<int>>& edges) {
	   GRAPH graph(n);
	   for (auto &e : edges) {
	     int from = e[0] - 1, to = e[1] - 1, cost = e[2];
	     add_undir_e(from, {to, cost}, graph);
	   }

	   auto fx = dijkstra(n - 1, graph);
		
	   // count number of ways to reach n - 1 from 0
	   vector<int> dp(n, -1);
	   function<int(int)> dfs = [&](int u) {
	     if (u == n - 1) return 1;
	     if (dp[u] != -1) return dp[u];
	     int ans = 0;
	     for (auto &e : graph[u]) {
		   int v = e.to;
		   if (fx[v] < fx[u]) {
		     ans = (ans + dfs(v)) % (1000000000+7);
		   }
	     }
	     return dp[u] = ans;
	   };
	   return dfs(0);
   }
};

