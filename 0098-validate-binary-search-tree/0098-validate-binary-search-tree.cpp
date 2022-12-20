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
#define all(v)      (v).begin(), (v).end()

class Solution {

    void inorder(TreeNode *root) {

        if (root->left)
            inorder(root->left);

        s.insert(root->val);
        v.push_back(root->val);

        if (root->right)
            inorder(root->right);

    }

public:
    vector<int> v;
    set<int> s;
    bool isValidBST(TreeNode *root) {
        // inorder traversal sol
        // check if array is sorted
        if (!root)
            return true;

        inorder(root);
        return is_sorted(all(v)) && (v.size() == s.size());
    }
};


