#include <bits/stdc++.h>
using namespace std;
#define ll          long long
#define lp(n)       for(ll i = 0; i < (n); ++i)
#define lp1(n)      for(ll i = 1; i <= (n); ++i)
#define tc          ll testcase;   cin>>testcase;   while(testcase--)
#define all(v)      (v).begin(), (v).end()
#define allr(v)     (v).rbegin(), (v).rend()
#define pb          push_back
#define watch(num)  cout<< #num <<": "<< num << "\n";
#define yes         cout<<"YES"<<endl
#define no          cout<<"NO"<<endl
#define improve     ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
int dx[4]{-1, 0, 1, 0};
int dy[4]{0, 1, 0, -1};
void hussien() {
    improve;
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
}

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

/* 3ein39
                    " وَأَن لَّيْسَ لِلْإِنسَانِ إِلَّا مَا سَعَى ﴿39﴾ وَأَنَّ سَعْيَهُ سَوْفَ يُرَى ﴿40﴾ ثُمَّ يُجْزَاهُ الْجَزَاء الْأَوْفَى "
                                      My way to My dream....
*/

class Solution {
    vector<vector<int>> v;
    int n,m;
    ll memo[200][200];
public:
    bool valid(int i, int j) {
        if (i >= n || j >= m || i < 0 || j < 0)
            return false;
        return true;
    }

    ll dp(int i, int j) {
        if (i == n - 1 && valid(i,j))
            return v[i][j];
        if (!valid(i,j))
            return 1e9;

        auto& ret = memo[i][j];
        if (ret != 1e9)
            return ret;

        ret = 1e9;
        ret = min(ret,dp(i+1, j));
        ret = min(ret,dp(i+1, j +1));
        ret = min(ret, dp(i+1, j - 1));

        return ret += v[i][j];
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        n = matrix.size(), m = matrix[0].size();
        v = matrix;

        for (auto& row: memo)
            for (auto& el : row)
                el = 1e9;
        ll ans = 1e9;

        for (int j = 0; j < m; ++j) {
            ans = min(ans, dp(0, j));
        }
        return ans;
    }
};
// int main() {
//     hussien();

//     vector<vector<int>> mat = {{2,1,3}, {6,5,4}, {7,8,9}};
//     Solution a;
//     cout << a.minFallingPathSum(mat);
//     return 0;
// }
