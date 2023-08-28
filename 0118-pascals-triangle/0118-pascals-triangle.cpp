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

const double PI = acos(-1.0);

double toDegreeFromMinute(double minute) {
    return minute / 60.0;
}

double toRadians(double degree) {
    return degree * PI / 180.0;
}

double toDegreeFromRadians(double radians) {
    return radians * 180.0 / PI;
}

double fixAngle(double A) {
    return A > 1 ? 1 : (A < -1 ? -1 : A);
}


struct Point {
    int x, y;
};

class Solution {
    int memo[50][50];
public:
    int pascal(int n, int k) {
        if (k == 0 || k == n)return 1;

        if (memo[n][k] != -1)return memo[n][k];

        return memo[n][k] = pascal(n - 1, k - 1) + pascal(n - 1, k);
    }
    vector<vector<int>> generate(int numRows) {
        memset(memo, -1, sizeof(memo));
        vector<vector<int>> ans;
        for (int i = numRows - 1; i >= 0; --i){
            vector<int> row;
            for (int j = 0; j <= i; ++j) {
                row.push_back(pascal(i, j));
            }
            ans.push_back(row);
        }
        reverse(all(ans));
        return ans;
    }
};
