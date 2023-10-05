class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        map<int, int> freq;
        for (auto& el : nums)
            freq[el]++;
        
        vector<int> ans;
        int n = nums.size();
        for (auto& [k, v] : freq)
            if (v > n/3)
                ans.push_back(k);
        
        return ans;
    }
};