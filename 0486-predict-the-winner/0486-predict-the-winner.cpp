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
    int n;
    vector<int> v;
    bool win = false;
public:
    bool solve(int l,int r ,int state, int p1, int p2) {
        if (l > r) {
            if (p1 >= p2)
                return true;
            return false;
        }
        if (state == 0) 
           return solve(l + 1, r, 1, p1 + v[l], p2) || solve(l, r - 1, 1, p1 + v[r], p2);
        else  
            return solve(l + 1, r, 0, p1, p2 + v[l]) && solve(l, r - 1, 0, p1, p2 + v[r]);
    }

    bool PredictTheWinner(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;
         n = nums.size();
         v = nums;
        return solve(l, r, 0, 0, 0);
    }
};
// int main() {
//     hussein();



//     return 0;
// }
