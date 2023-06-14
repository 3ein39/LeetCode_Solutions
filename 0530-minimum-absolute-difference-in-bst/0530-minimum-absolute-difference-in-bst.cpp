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
    int ans = 1e7;
    TreeNode* prev;
    
    void answer(TreeNode* cur) {
        if (!cur)
            return;
        
        answer(cur->left);
        
        if (prev != nullptr)
            ans = min(ans, cur->val - prev->val);
        prev = cur;
        answer(cur->right);
    }
    
    int getMinimumDifference(TreeNode* root) {
        answer(root);
        
        return ans;
    }
};