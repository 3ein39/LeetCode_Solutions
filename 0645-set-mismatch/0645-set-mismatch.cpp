class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int> found(nums.size() + 1, 0);
        for (auto& el : nums) {
            found[el]++;
        }
        
        vector<int> ans;
        for (int i = 1; i <= nums.size(); ++i) {
            if (found[i] == 2)
                ans.push_back(i);
            if (found[i] == 0)
                ans.push_back(i);
        }
        
        if (found[ans[0]] == 0)
            reverse(ans.begin(), ans.end());
        
        return ans;
    }
};