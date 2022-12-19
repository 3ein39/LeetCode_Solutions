#include<bits/stdc++.h>

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
#define Node        ListNode
int dx[4]{-1, 0, 1, 0};
int dy[4]{0, 1, 0, -1};

/* 3ein39
                    " وَأَن لَّيْسَ لِلْإِنسَانِ إِلَّا مَا سَعَى ﴿39﴾ وَأَنَّ سَعْيَهُ سَوْفَ يُرَى ﴿40﴾ ثُمَّ يُجْزَاهُ الْجَزَاء الْأَوْفَى "
                                      My way to My dream....
*/


void hussein() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    improve;
}



class Solution {
public:
    string parenthesize(TreeNode* cur) {
        string rep = "(" + to_string(cur->val);
        
        vector<string> v;
        if (cur->left)
            v.push_back(parenthesize(cur->left));
        else
            v.push_back("()");
        
        if (cur->right)
            v.push_back(parenthesize(cur->right));
        else
            v.push_back("()");

        sort(all(v));
        
        for (auto& el : v)
            rep += el;
        
        rep += ")";
        
        return rep;
    }
    
    bool flipEquiv(TreeNode *root1, TreeNode *root2) {
        if (!root1 && !root2) return true;
        
        if (!root1 || !root2)
            return false;
        
        return parenthesize(root1) == parenthesize(root2);
    }
};
