#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define lp(n) for (ll i = 0; i < (n); ++i)
#define lp1(n) for (ll i = 1; i <= (n); ++i)
#define tc         \
  ll testcase;     \
  cin >> testcase; \
  while (testcase--)
#define all(v) (v).begin(), (v).end()
#define allr(v) (v).rbegin(), (v).rend()
#define watch(num) cout << #num << ": " << num << "\n";
#define pb push_back
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#define improve                     \
  ios_base::sync_with_stdio(false); \
  cin.tie(NULL);                    \
  cout.tie(NULL)
int dx4[4]{-1, 0, 1, 0};
int dy4[4]{0, 1, 0, -1};
int dx8[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dy8[8] = {0, 1, 1, 1, 0, -1, -1, -1};

template<typename T>
istream &operator>>(istream &input, vector<T> &data) {
  for (T &x : data) input >> x;
  return input;
}

template<typename T>
ostream &operator<<(ostream &output, const vector<T> &data) {
  for (const T &x : data) output << x << " ";
  return output;
}

void hussein() {
  improve;
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif
}

// class Node {
// public:
//     int val;
//     vector<Node*> neighbors;
//     Node() {
//         val = 0;
//         neighbors = vector<Node*>();
//     }
//     Node(int _val) {
//         val = _val;
//         neighbors = vector<Node*>();
//     }
//     Node(int _val, vector<Node*> _neighbors) {
//         val = _val;
//         neighbors = _neighbors;
//     }
// };

class Solution {
	unordered_map<Node*, Node*> seen;
  public:
	Node* cloneGraph(Node* node) {
		if (node == nullptr)
			return nullptr;

		if (!seen.count(node)) {
			seen[node] = new Node(node->val);
			for (auto& neighbour : node->neighbors) {
				seen[node]->neighbors.push_back(cloneGraph(neighbour));
			}
		}
		
		return seen[node];
	}
};
