#include <bits/stdc++.h>

using namespace std;

#define ull         unsigned long long
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
int dx[4]{-1, 0, 1, 0};
int dy[4]{0, 1, 0, -1};
const int OO = 10000000;


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
/* 3ein39
                    " وَأَن لَّيْسَ لِلْإِنسَانِ إِلَّا مَا سَعَى ﴿39﴾ وَأَنَّ سَعْيَهُ سَوْفَ يُرَى ﴿40﴾ ثُمَّ يُجْزَاهُ الْجَزَاء الْأَوْفَى "
                                      My way to My dream....
*/
class Solution {
    vector<int> cc;
public:
    bool valid(int i, int j, vector<vector<int>>& g) {
        if (i < 0 || j < 0 || i >= g.size() || j >= g[0].size() || g[i][j] == 0)
            return false;

        return true;
    }

    void dfs(int i, int j, vector<vector<int>>& g) {
        if (!valid(i, j, g))
            return;

        g[i][j] = 0;
        cc.pb(i * g[0].size() + j);

        for (int k = 0; k < 4; ++k) {
            int ni = i + dx[k], nj = j + dy[k];
            dfs(ni, nj, g);
        }
    }

    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        int n = land.size(), m = land[0].size();

        vector<vector<int>> ans;

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (valid(i, j, land)) {
                    cc.clear();
                    dfs(i, j, land);

                    // get the min and max point
                    int pMax = *max_element(all(cc));
                    int pMin = *min_element(all(cc));

                    vector<int> coords(4);
                    coords[0] = pMin / land[0].size();
                    coords[1] = pMin % land[0].size();
                    coords[2] = pMax / land[0].size();
                    coords[3] = pMax % land[0].size();

                    ans.pb(coords);
                }
            }
        }
        return ans;
    }
};
// int main() {
//     hussein();

//     vector<vector<int>> v = {{1,1,0,0,0,1}, {1,1,0,0,0,0}};

//     Solution s;
//     cout << s.findFarmland(v);


//     return 0;
// }
