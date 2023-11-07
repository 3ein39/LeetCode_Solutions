#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <unordered_map>
using namespace std;
class Solution {
public:

// TC : O(n)
// space : O(n)

// bucket sort approach
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        for (auto& el : nums)  // O(n)
            freq[el]++;
        
        vector<vector<int>> bucket(nums.size() + 1);
        for (auto&[key, val] : freq) {
            bucket[val].push_back(key);
        }
        
        // loop from the highest freq -end of buckets- to get k maxs
        vector<int> ans;
        for (int i = nums.size(); i >= 0; --i) {
            if (ans.size() >= k) break;
            
            if (!bucket[i].empty()) {
                ans.insert(ans.end(), bucket[i].begin(), bucket[i].end());
            }
        }
        
        return ans;
    }
};