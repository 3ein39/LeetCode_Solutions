#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;



//   struct TreeNode {
//       int val;
//       TreeNode *left;
//       TreeNode *right;
//       TreeNode() : val(0), left(nullptr), right(nullptr) {}
//       TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//       TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
//   };

#define ll long long

class Solution {
public:
    bool solve(TreeNode* root, long long  min = -1e12, long long max = 1e12) {
        if (!root)
            return true;
            
        if (root->val < min || root->val > max)
            return false;
            
        return solve(root->left, min, root->val - 1ll) && solve(root->right,root->val + 1ll , max);
    }

    bool isValidBST(TreeNode* root) {
        if (!root) 
            return false;
        
        return solve(root); 
    }
};