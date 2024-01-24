class Solution {
	int ans = 0;
  public:
	int pseudoPalindromicPaths (TreeNode* root, int count = 0) {
		if (!root) return 0;
		
		count ^= 1 << root->val;
		if (!root->left && !root->right) return __builtin_popcount(count) <= 1;
		
		return pseudoPalindromicPaths(root->left, count) + pseudoPalindromicPaths(root->right, count);
	}
};
