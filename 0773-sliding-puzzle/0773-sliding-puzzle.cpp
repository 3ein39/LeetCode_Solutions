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

vector<vector<int>> ans = {{1, 2, 3},
                           {4, 5, 0}};

bool found(vector<vector<int>> &mat) {
    return mat == ans;
}

pair<int, int> getidx(vector<vector<int>> &mat) {
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (mat[i][j] == 0)
                return {i, j};
        }
    }
    return {-1, -1};
}

void process(vector<vector<int>> &mat, int i, int j, int ni, int nj, queue<vector<vector<int>>> &q,
             vector<vector<vector<int>>> &vis) {
    if (ni < 0 || nj < 0 || ni >= 2 || nj >= 3)
        return;

    vector<vector<int>> newMat = mat;
    swap(newMat[i][j], newMat[ni][nj]);

    for (auto & el : vis) {
        if (el == newMat)
            return;
    }
    
        q.push(newMat);
        vis.push_back(newMat);
}

class Solution {
public:
    int slidingPuzzle(vector<vector<int>> &board) {
        vector<vector<vector<int>>> vis;
        queue<vector<vector<int>>> q;

        vis.push_back(board);
        q.push(board);

        int length = 0;
        while (!q.empty()) {
            int sz = q.size();

            while (sz--) {
                auto mat = q.front();
                q.pop();

                if (found(mat))
                    return length;

                auto[i, j] = getidx(mat);

                for (int k = 0; k < 4; ++k) {
                    int ni = i + dx[k], nj = j + dy[k];

                    process(mat, i, j, ni, nj, q, vis);
                }
            }
            ++length;
        }

        return -1;
    }
};

// int main() {
//     vector<vector<int>> v = {{1, 2, 3},
//                              {4, 0, 5}};
//     Solution a;

//     a.slidingPuzzle(v);
//     return 0;
// }
