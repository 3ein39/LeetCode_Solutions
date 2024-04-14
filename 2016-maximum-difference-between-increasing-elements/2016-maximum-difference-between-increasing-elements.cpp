class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        // o(n)
        int mn = 1e9, n = nums.size(), ans = -1;
        for (int i = 0; i < n; ++i) {
            if (nums[i] <= mn)
                mn = nums[i];
            else
                ans = max(nums[i] - mn, ans);
        }
        
        return ans;
    }
};