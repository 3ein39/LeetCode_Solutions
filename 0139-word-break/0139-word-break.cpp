#include <bits/stdc++.h>

using namespace std;

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

class Solution {
    string s;
    int memo[2000];
    unordered_set<string> words;
public:
    bool solve(int start) {
        if (start == s.size())
            return true;

        if (memo[start] != -1)
            return memo[start];

        for (int i = start; i < s.size(); ++i) {
//            watch(s.substr(start, start - i + 1));
            if (words.count(s.substr(start,i - start + 1)) && solve(i + 1)) {
                memo[start] = true;
                return true;
            }
        }
        return memo[start] = false;
    }

    bool wordBreak(const string s_, const vector<string>& wordDict) {
        s = s_;

        memset(memo, -1, sizeof memo);

        words.insert(all(wordDict));

        return solve(0);
    }
};


// int main() {
//     watch(Solution().wordBreak("leetcode", {"leet", "code"}));
// }


