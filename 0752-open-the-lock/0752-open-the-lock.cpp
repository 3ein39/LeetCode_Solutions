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

string next(string& node, int i) {
    int digit = node[i] - '0';
    ++digit;
    
    if (digit <= 9) {
        string ans = node;
        ans[i] = digit + '0';
        return ans;
    }
    else {
        string ans = node;
        ans[i] = '0';
        return ans;
    }
    return "";
}

string last(string &node, int i) {
     int digit = node[i] - '0';
    --digit;
    
    if (digit <= 9 && digit >= 0) {
        string ans = node;
        ans[i] = digit + '0';
        return ans;
    }
    else {
        string ans = node;
        ans[i] = '9';
        return ans;
    }   
    return "";
}

class Solution {
public:
    int openLock(vector<string> &deadends, string target) {
        queue<string> q;
        map<string, bool> vis;

        q.push("0000");
        
        int ans = 0;
        while (!q.empty()) {
            int sz = q.size();
            
            while (sz--) {
                string node = q.front();
                q.pop();
                
                if (node == target)
                    return ans;
                
                if (vis.count(node) || find(deadends.begin(), deadends.end(), node) != deadends.end())
                    continue;
                
                vis[node] = true;
                
                for (int i = 0; i < 4; ++i) {
                    q.push(next(node, i));
                    q.push(last(node, i));
                }
            }
            ans++;
        }
        
        return -1;

    }
};

// int main() {
//     hussein();


//     return 0;
// }
