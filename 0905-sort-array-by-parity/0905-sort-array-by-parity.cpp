class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        vector<int> evens, odds;
        for (auto& el : nums) {
            if (el & 1)
                odds.push_back(el);
            else
                evens.push_back(el);
        }
        vector<int> ans = evens;
        for (auto& el : odds)
            ans.push_back(el);
        return ans;
    }
};