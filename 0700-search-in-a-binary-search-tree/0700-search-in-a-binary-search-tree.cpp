class Solution {
public:
    TreeNode *searchBST(TreeNode *root, int val) {
        // iterative sol
        if (!root)
            return nullptr;
        
        while (val != root->val) {
            if (val > root->val) {
                if (root->right) {
                    root = root->right;
                    continue;
                }
                else
                    return nullptr;
            }
            else if (val < root->val) {
                if (root->left) {
                    root = root->left;
                    continue;
                }
                else
                    return nullptr;
            }
        }
        
        return root;
    }
};
