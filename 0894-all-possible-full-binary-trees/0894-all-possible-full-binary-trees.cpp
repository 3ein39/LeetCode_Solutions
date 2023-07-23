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
  // struct TreeNode {
  //     int val;
  //     TreeNode *left;
  //     TreeNode *right;
  //     TreeNode() : val(0), left(nullptr), right(nullptr) {}
  //     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  //     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  // };

class Solution {
    vector<TreeNode*> ans;
    unordered_map<int, vector<TreeNode*>> memo;
public:
    vector<TreeNode*> dp(int n) {
        if (n == 0)
            return {};
        if (n == 1) {
            TreeNode* node = new TreeNode(0);
            return {node};
        }
        if (memo.count(n))
            return memo[n];

        vector<TreeNode*> res;
        for (int i = 0; i < n; ++i) {
            int l = i, r = n - i - 1;

            auto left = dp(l);
            auto right = dp(r);

            for (auto& t1 : left) {
                for (auto& t2 : right) {
                    TreeNode* root = new TreeNode(0, t1, t2);
                    res.push_back(root);
                }
            }
        }
            return memo[n] = res;

    }

    vector<TreeNode*> allPossibleFBT(int n) {
       return dp(n);
    }
};

// int main() {
//      hussein();


//      return 0;
//  }
