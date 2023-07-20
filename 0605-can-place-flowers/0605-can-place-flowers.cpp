#include <bits/stdc++.h>

using namespace std;

#define ll          long long
#define lp(n)       for(ll i = 0; i < (n); ++i)
#define lp1(n)      for(ll i = 1; i <= (n); ++i)
#define tc          ll testcase;   cin>>testcase;   while(testcase--)
#define all(v)      (v).begin(), (v).end()
#define allr(v)     (v).rbegin(), (v).rend()
//#define fi          first
//#define se          second
#define pb          push_back
#define yes         cout<<"YES"<<endl
#define no          cout<<"NO"<<endl
#define improve     ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define watch(num)  cout<< #num <<": "<< num << "\n";
int dx[4]{-1, 0, 1, 0};
int dy[4]{0, 1, 0, -1};
int dx8[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dy8[8] = {0, 1, 1, 1, 0, -1, -1, -1};

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
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int ans = 0;
        if (flowerbed.size() > 2) {
            if (!flowerbed[0] && !flowerbed[1]) flowerbed[0] = 1, ++ans;
            if (!flowerbed[flowerbed.size() - 1] && !flowerbed[flowerbed.size() - 2])
                flowerbed[flowerbed.size() - 1] = 1, ++ans;
        }
        else {
            if (!flowerbed[0]) ++ans;
        }
        for (int i = 1; i < flowerbed.size() - 1; ++i) {
            if (!flowerbed[i] && !flowerbed[i - 1] && !flowerbed[i + 1])
                flowerbed[i] = 1, ++ans;
        }



        return ans >= n;
    }
};

// int main() {
//      hussein();



//      return 0;
//  }
