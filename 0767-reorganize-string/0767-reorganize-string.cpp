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
public:
    string reorganizeString(string s) {
        std::map<char, int> freq;
        int mx = 0;
        for (auto& el : s) {
            freq[el]++;
            mx = max(mx, freq[el]);
        }

        string ans;
        priority_queue<pair<int, char>> pq;
        for (auto& el : freq) {
            pq.push({el.second, el.first});
        }

        while (!pq.empty()) {
            auto top = pq.top();
            pq.pop();
            if (ans.empty() || ans.back() != top.second) {
                ans += top.second;
                if (--top.first > 0)
                    pq.push(top);
            }
            else {
                if (pq.empty())
                    return "";
                ans += pq.top().second; 
                auto el = pq.top();
                pq.pop();
                el.first--;
                if (el.first)
                    pq.push(el);
                pq.push(top);
            }

        }

        for (int i = 0; i < ans.size(); ++i)
        {
            if (ans[i] == ans[i + 1])
                return "";
        }
        return ans;
    }
};


// int main() {
//     hussein();


//     return 0;
// }
