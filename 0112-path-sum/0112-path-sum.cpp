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
#define pb          push_back
#define improve     ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
int dx[4]{-1, 0, 1, 0};
int dy[4]{0, 1, 0, -1};

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
 // struct TreeNode {
 //      int val;
 //      TreeNode *left;
 //     TreeNode *right;
 //     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 //      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 //     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 //  };
class Solution {
   public:
    TreeNode* f;
    bool solve(TreeNode* root, int rem, map<pair<TreeNode*, int>, bool>&dp) {
	  if (!root)
          return false;
    
        
	  
	  if (dp.count({root, rem}))
	    return dp[{root, rem}];
	  
	  bool ch1 = false, ch2 = false;
	  
	  rem = rem - root->val;
        if (rem == 0 && !root->left && !root->right)
            return true;
	  
	  // if (root->left)
	    ch1 = max(ch1, solve(root->left, rem, dp));
	  
	  // if (root->right)
	    ch2 = max(ch2, solve(root->right, rem, dp));
	  
	  return dp[{root, rem}] = max(ch1, ch2);
    }
    
    bool hasPathSum(TreeNode* root, int targetSum) {
		map<pair<TreeNode*, int>, bool> dp;
        if (!root) return false;
        f = root;
	    return solve(root, targetSum, dp);
    }
};

