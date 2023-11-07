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

// TC : O(n*log(n))
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        for (auto& el : nums)  // O(n)
            freq[el]++;
        
        vector<pair<int, int>> v;
        for (auto&[key, val] : freq) {
            v.push_back({key, val});
        }
        
        // O(n.logn)
        sort(v.begin(), v.end(), [&](pair<int, int> &a,pair<int, int> &b) {
          return a.second > b.second;  
        });
        
        vector<int> ans;
        for (int i = 0; i < k; ++i) {
            ans.push_back(v[i].first);
        }
        
        return ans;
    }
};