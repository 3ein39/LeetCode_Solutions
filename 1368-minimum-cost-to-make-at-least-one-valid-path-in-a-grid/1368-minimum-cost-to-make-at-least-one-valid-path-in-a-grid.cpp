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



#define GRAPH vector<vector<edge>>

//void add_undirected_edge(int from, int to, GRAPH &graph) {
//    graph[from].pb(to);
//    graph[to].pb(from);
//}


void hussein() {
    improve;
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
}


class Solution {
    int n,m;
   public:
  struct edge {
	int to, cost;
	edge(int to, int cost) : to(to), cost(cost) {}
  };
  vector<int> dijkstra(int source, GRAPH &graph) {
	vector<int> dist(graph.size(), INT_MAX);
	dist[source] = 0;
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push({0, source});
	while (!pq.empty()) {
	  auto top = pq.top();
	  pq.pop();
	  int u = top.second;
	  int d = top.first;
	  if (d > dist[u])continue;
	  for (auto &e: graph[u]) {
		if (dist[u] + e.cost < dist[e.to]) {
		  dist[e.to] = dist[u] + e.cost;
		  pq.push({dist[e.to], e.to});
		}
	  }
	}
	return dist;
  }
  static void add_directed_edge(int from, edge e, GRAPH &graph) {
	graph[from].pb(e);
  }
    int minCost(vector<vector<int>>& grid) {
	    // 0/1 edge, build graph then dijkstra
		vector<vector<edge>> graph(grid.size() * grid[0].size());
	    n = grid.size(), m = grid[0].size();
	    for (int i = 0; i < grid.size(); ++i) {
	        for (int j = 0; j < grid[0].size(); ++j) {
				int index = i * m + j;
				if (grid[i][j] == 1) {
				  // you can go right with cost 0 and 1 otherwise
				  if (j + 1 < m) {
					add_directed_edge(index, {index + 1, 0}, graph);
				  }
				  if (j - 1 >= 0) {
					add_directed_edge(index, {index - 1, 1}, graph);
				  }
				  if (i + 1 < n) {
					add_directed_edge(index, {index + m, 1}, graph);
				  }
				  if (i - 1 >= 0) {
					add_directed_edge(index, {index - m, 1}, graph);
				  }
				}
				else if (grid[i][j] == 2) {
				  // you can go left with cost 0 and 1 otherwise
				  if (j + 1 < m) {
					add_directed_edge(index, {index + 1, 1}, graph);
				  }
				  if (j - 1 >= 0) {
					  add_directed_edge(index, {index - 1, 0}, graph);
				  }
				  if (i + 1 < n) {
					  add_directed_edge(index, {index + m, 1}, graph);
				  }
				  if (i - 1 >= 0) {
					  add_directed_edge(index, {index - m, 1}, graph);
				  }

				}
				else if (grid[i][j] == 4) {
				  // you can go up with cost 0 and 1 otherwise
				  if (j + 1 < m) {
					  add_directed_edge(index, {index + 1, 1}, graph);
				  }
				  if (j - 1 >= 0) {
					  add_directed_edge(index, {index - 1, 1}, graph);
				  }
				  if (i + 1 < n) {
					  add_directed_edge(index, {index + m, 1}, graph);
				  }
				  if (i - 1 >= 0) {
					  add_directed_edge(index, {index - m, 0}, graph);
				  }
				}
				else if (grid[i][j] == 3) {
				  // you can go down with cost 0 and 1 otherwise
				  if (j + 1 < m) {
					  add_directed_edge(index, {index + 1, 1}, graph);
				  }
				  if (j - 1 >= 0) {
					  add_directed_edge(index, {index - 1, 1}, graph);
				  }
				  if (i + 1 < n) {
					  add_directed_edge(index, {index + m, 0}, graph);
				  }
				  if (i - 1 >= 0) {
					  add_directed_edge(index, {index - m, 1}, graph);
				  }
			  }
	      }
	  }
	  vector<int> dist = dijkstra(0, graph);
	  return dist[n * m - 1];
	}
};
// int main() {
//     hussein();

// 	Solution s;
//     	vector<vector<int>> grid = {{1,1,3}, {3,2,2}, {1,1,4}};
//         	cout << s.minCost(grid) << endl;

//     return 0;
// }
