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
#define Node        ListNode
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
    map<pair<pair<int, int>, int>, bool> memo; // i, j, k
    string s1,s2,s3;
public:
    bool dp(int i, int j, int k) {
        if (k == s3.size()) return true;
        
        if (memo.count({{i, j}, k})) return memo[{{i, j}, k}];
        
        bool ans = false;
        if (i < s1.size() && s1[i] == s3[k]) ans |= dp(i + 1, j, k + 1);
        if (j < s2.size() && s2[j] == s3[k]) ans |= dp(i, j + 1, k + 1);
        
        return memo[{{i, j}, k}] = ans;
    }
    bool isInterleave(string s1_, string s2_, string s3_) {
        s1 = s1_;
        s2 = s2_;
        s3 = s3_;
        if(s1.size() + s2.size() != s3.size())return false;
        
        return dp(0,0,0);
        
    }
};
