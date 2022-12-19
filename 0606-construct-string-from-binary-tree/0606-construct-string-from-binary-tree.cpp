/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
      string parenthesize(TreeNode *cur) {
        string rep = "(" + to_string(cur->val);

        if (cur->right && !cur->left){
            rep += "()";
            goto here;
        }

        if (cur->left)
            rep += parenthesize(cur->left);

        here:
        if (cur->right)
            rep += parenthesize(cur->right);
        
        
        rep += ")";

        return rep;
    }


    string tree2str(TreeNode *root) {
        string ans = parenthesize(root);
        
        ans.pop_back();
        return ans.substr(1, ans.size());
    }
};
