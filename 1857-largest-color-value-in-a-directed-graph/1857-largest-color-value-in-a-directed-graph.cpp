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
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {


        int n = colors.length();
        vector<vector<int>> graph(n);
        vector<int> indegree(n, 0);

        for (auto &edge: edges) {
            indegree[edge[1]]++;

            graph[edge[0]].push_back(edge[1]);
        }

        queue<int> q;

        vector<vector<int>> mxColor(n, vector<int>(26, 0));
        for (int i = 0; i < n; ++i) {
            if (!indegree[i])
                q.push(i);
        }

        int answer = 0;
        while (!q.empty()) {
            int sz = q.size();

            while (sz--) {
                int node = q.front();
                q.pop();
                int color = colors[node] - 'a';
                ++mxColor[node][color];

                answer = max(answer, mxColor[node][color]);

                for (auto& ne : graph[node]) {
                    indegree[ne]--;

                    if (!indegree[ne])
                        q.push(ne);

                    for (int i = 0; i < 26; ++i) {
                        mxColor[ne][i] = max(mxColor[node][i], mxColor[ne][i]);
                    }
                }
            }
        }
        // checking cycles
        for (int i = 0; i < n; ++i) {
            if (indegree[i])
                return -1;
        }

        return answer;
    }

};
// int main() {
//     hussein();

//     return 0;
// }
