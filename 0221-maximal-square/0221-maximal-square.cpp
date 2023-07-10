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
int dx4[4]{-1, 0, 1, 0};
int dy4[4]{0, 1, 0, -1};
int dx8[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dy8[8] = {0, 1, 1, 1, 0, -1, -1, -1};

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
int memo[301][301];
int n,m;
vector<vector<char>> v;
class Solution {
public:
    bool valid(int i, int j) {
        if (i < 0 || j < 0 || i >= n || j >= m || v[i][j] == '0')
            return false;
        return true;
    }

    ll dp(int i, int j) {
        if (!valid(i,j))
            return 0;

        auto& ret = memo[i][j];
        if (~ret)
            return ret;

        ret = 1;
        int cnt = 0;
        if (valid(i+1,j+1)) ++cnt;
        if (valid(i+1,j)) ++cnt;
        if (valid(i,j+1)) ++cnt;

        if (cnt == 3)
            ret += min({dp(i+1, j+1), dp(i + 1, j), dp(i, j + 1)});
        return ret;
    }

    int maximalSquare(vector<vector<char>>& matrix) {
        n = matrix.size(), m = matrix[0].size();
        memset(memo, -1, sizeof memo);
        v = matrix;
        ll ans = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (matrix[i][j] == '1')
                    ans = max(ans, dp(i,j));
            }
        }
        return ans * ans;
    }
};

// int main() {
//     hussien();

//     vector<vector<char>> test(4, vector<char>(5));
//     for (int i = 0; i < 4; ++i) {
//         for (int j = 0; j < 5; ++j) {
//             cin >> test[i][j];
//         }
//     }

//     Solution a;
//     cout << a.maximalSquare(test);

//     return 0;
// }
