#include <bits/stdc++.h>

using namespace std;

#define ll          long long
#define lp(n)       for(ll i = 0; i < (n); ++i)
#define lp1(n)      for(ll i = 1; i <= (n); ++i)
#define tc          ll testcase;   cin>>testcase;   while(testcase--)
#define all(v)      (v).begin(), (v).end()
#define allr(v)     (v).rbegin(), (v).rend()
#define fi          first
#define se          second
#define pb          push_back
#define yes         cout<<"YES"<<endl
#define no          cout<<"NO"<<endl
#define improve     ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define watch(num)  cout<< #num <<": "<< num << "\n";
int dx[4]{-1, 0, 1, 0};
int dy[4]{0, 1, 0, -1};
int dx8[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dy8[8] = {0, 1, 1, 1, 0, -1, -1, -1};
#define endl        '\n';
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

class Solution {
    vector<vector<double>> dp;
public:
    double solve(int Arem, int Brem) {
        if (Arem <= 0 && Brem > 0) {
            return 1.0;
        }
        if (Arem <= 0 && Brem <= 0) {
            return 0.5;
        }

        if (Brem <= 0 && Arem > 0) return 0.0;

        if (dp[Arem][Brem] != -1) return dp[Arem][Brem];
        auto &ans = dp[Arem][Brem];

        return dp[Arem][Brem] = 0.25*(solve(Arem-100,Brem)+solve(Arem-75,Brem-25)+solve(Arem-50,Brem-50)+solve(Arem-25,Brem-75));

    }
    double soupServings(int n) {
            if (n >= 5000) return 1.0;

            dp.resize(n + 1, vector<double>(n + 1, -1.0));

            return solve(n, n);
    }
};

// int main() {
//     hussein();



//     return 0;
// }
