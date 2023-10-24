#include <bits/stdc++.h>
using namespace std;

//   struct TreeNode {
//       int val;
//       TreeNode *left;
//       TreeNode *right;
//       TreeNode() : val(0), left(nullptr), right(nullptr) {}
//       TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//       TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
//   };
 #define ll     long long
class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        queue<TreeNode*>q;
        q.push(root);
        
        if (!root)
            return {};
        
        vector<int> ans;
        while (!q.empty()) {
            int sz = q.size();
            long long mx = -1e9*3;
            while (sz --) {
                auto node = q.front();
                q.pop();
                
                mx = max(mx, node->val*1ll);
                
                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);
            }
            ans.push_back(mx);
        }
        return ans;
    }
};