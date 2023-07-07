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
    string str;
    int n;
    int memo[100 + 1];
public:
    bool valid(int i) {
        return i < n;
    }
    
    int dp(int i) {
        if (i >= n - 1 && str[i] != '0')
            return 1;

        if (i >= n - 1 && str[i] == '0')
            return 0;
        
        auto& ret = memo[i];
        if (~ret)
            return ret;
        
        ret = 0;
        if (str[i] >= '1' && str[i] <= '9')
            ret += dp(i + 1);
        
        if (valid(i + 1)) {
            string temp;
            temp.push_back(str[i]);
            temp.push_back(str[i+1]);
            
            if (temp >= "10" && temp <= "26")
                ret += dp(i + 2);
        }
        
        return ret;
    }
    
    int numDecodings(string s) {
        str = s;
        n = s.size();
        ::memset(memo, -1, sizeof memo);
        return dp(0);
    }
};


// int main() {
//     hussien();



//     return 0;
// }
