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
    TreeNode* searchBST(TreeNode* root, int val) {
        // recursive sol
        TreeNode* node = nullptr;
        
        if (val == root->val)
            return root;
        
        if (val > root->val) {
            if (root->right)
                node = searchBST(root->right, val);
        }
        else if (val < root->val) {
            if (root->left)
                node = searchBST(root->left, val);
        }
        
        return node;
    }
};
