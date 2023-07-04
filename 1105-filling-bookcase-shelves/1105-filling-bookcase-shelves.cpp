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

/* 3ein39
                    " وَأَن لَّيْسَ لِلْإِنسَانِ إِلَّا مَا سَعَى ﴿39﴾ وَأَنَّ سَعْيَهُ سَوْفَ يُرَى ﴿40﴾ ثُمَّ يُجْزَاهُ الْجَزَاء الْأَوْفَى "
                                      My way to My dream....
*/

class Solution {
    ll memo[1000 + 1];
    int n;
    int max_w;
    vector<vector<int>> v;
public:
    ll dp(int idx) {
        if (idx >= n)
            return 0;

        auto& ret = memo[idx];
        if (~ret)
            return ret;

        ret = 1e8;
        ll total_w = 0, max_h = 0;
        for (int k = idx; k < n; ++k) {
         ll cur_h  = v[k][1], cur_w = v[k][0];
         total_w += cur_w;
         max_h = max(cur_h, max_h);

         if(total_w > max_w)
             break;

         ret = min(ret, max_h + dp(k + 1));
        }
        return ret;
    }
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        n = books.size();
        max_w = shelfWidth;
        v = books;
        ::memset(memo, -1, sizeof memo);
        auto ans = dp (0);
        return ans;
    }
};

// int main() {
//     hussein();

//  Solution a;
//  vector<vector<int>> v = {{1,1}, {2,3},{2,3},{1,1},{1,1},{1,1},{1,2}};
//  cout << a.minHeightShelves(v, 4);
//     return 0;
// }
