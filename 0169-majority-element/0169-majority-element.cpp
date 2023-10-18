#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> mp; // {num, freq}
        for (auto& el : nums)
            mp[el]++;
        
        for (auto&[key, val] : mp) {
            if (val > nums.size() / 2)
                return key;
        }
        return -1;
    }   
};