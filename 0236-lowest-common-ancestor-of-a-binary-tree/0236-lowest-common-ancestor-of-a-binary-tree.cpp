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
#define Node        ListNode
int dx[4]{-1, 0, 1, 0};
int dy[4]{0, 1, 0, -1};

/* 3ein39
                    " وَأَن لَّيْسَ لِلْإِنسَانِ إِلَّا مَا سَعَى ﴿39﴾ وَأَنَّ سَعْيَهُ سَوْفَ يُرَى ﴿40﴾ ثُمَّ يُجْزَاهُ الْجَزَاء الْأَوْفَى "
                                      My way to My dream....
*/



class Solution {
    vector<TreeNode *> v;
    bool pf = false, qf = false;
public:
    void traverse(TreeNode *cur, TreeNode *p, TreeNode *q) {

        if (cur->left)
            traverse(cur->left, p, q);

        if (cur->right)
            traverse(cur->right, p, q);

        if (p == cur)
            pf = true;
        if (q == cur)
            qf = true;

        if (pf && qf)
            v.pb(cur);
    }
    
    bool valid(TreeNode* node, TreeNode* p, TreeNode* q) {
        if (node->left)
            valid(node->left, p,q);
        
        if (node->right)
            valid(node->right,p ,q);
        
        if (p == node)
            pf = true;
        if (q == node)
            qf = true;
        
        if(qf && pf)
            return true;
        return false;
    }

    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
        traverse(root, p, q);

        for (auto& node :v) {
            pf = false, qf = false;
            if (valid(node,p,q))
                return node;
        }
        return nullptr;
    }
};
