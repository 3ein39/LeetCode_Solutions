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
public:
    bool buddyStrings(string s, string goal) {
        if (s.size() != goal.size()) return false;

        map<char, int> freq1, freq2;
        for (int i = 0; i < s.size(); ++i) {
            freq1[s[i]]++, freq2[goal[i]]++;
        }
        bool same = (freq1 == freq2);

        if (s == goal) {
            for (auto& [chr, fre] : freq1)
                if (fre > 1) return true;
            return false;
        }
        else {
            int idx = -1, jdx = -1;
            for (int i = 0; i < s.size(); ++i) {
                if (s[i] != goal[i]) {
                    if (idx == -1) idx = i;
                    else if (jdx == -1) jdx = i;
                    else
                        return false;
                }
            }
            if (jdx == -1) return false;
            return s[idx] == goal[jdx] && s[jdx] == goal[idx];
        }
        return false;

    }
};

// int main() {
//     Solution a;
//     cout << a.buddyStrings("ab", "ba");
// }
