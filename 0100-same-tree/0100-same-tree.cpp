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
 // struct TreeNode {
 //       int val;
 //       TreeNode *left;
 //       TreeNode *right;
 //       TreeNode() : val(0), left(nullptr), right(nullptr) {}
 // TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 // TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 //  };
class Solution {
  public:
   bool isSameTree(TreeNode* p, TreeNode* q) {
	   if(p == nullptr && q == nullptr) return true;
	   if(p == nullptr || q == nullptr) return false;
	   if(p->val != q->val) return false;
	   return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
   }
};
