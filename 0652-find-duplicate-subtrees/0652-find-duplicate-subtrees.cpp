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

// struct TreeNode {
//     int val;
//     TreeNode *left;
//     TreeNode *right;

//     TreeNode() : val(0), left(nullptr), right(nullptr) {}

//     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

//     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
// };

class Solution {
    unordered_map<string, TreeNode *> str_toObj;
    vector<string> representations;
public:
    string parenthesize(TreeNode *cur) {
        string rep = "(" + to_string(cur->val);
        if (cur->left)
            rep += parenthesize(cur->left);
        else
            rep += "()";

        if (cur->right)
            rep += parenthesize(cur->right);
        else
            rep += "()";

        rep += ")";
        
        str_toObj[rep] = cur;
        representations.push_back(rep);

        return rep;
    }

    vector<TreeNode *> findDuplicateSubtrees(TreeNode *root) {
        parenthesize(root);

        vector<TreeNode *> ans;
        sort(all(representations));

                for (int i = 0; i < representations.size() - 1; ++i) {
            if (representations[i] == representations[i + 1]) {
                if (find(all(ans), str_toObj[representations[i]]) == ans.end())
                    ans.push_back(str_toObj[representations[i]]);
            }
        }


        return ans;

    }
};


// int main() {
//     TreeNode *root = new TreeNode(1);

//     root->left = new TreeNode(2);

//     root->left->left = new TreeNode(4);
//     root->right = new TreeNode(3);

//     root->right->left = new TreeNode(2);
//     root->right->left->left = new TreeNode(4);
//     Solution test;

//     test.findDuplicateSubtrees(root);
// }
