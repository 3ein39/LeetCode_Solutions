#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string, vector<string>> hashMap;
        
        for (auto el : strs) {
            sort(el.begin(), el.end());
            hashMap[el] = {};
        }
        
        vector<string> sorted(strs);
        for (auto& el : sorted)
            sort(el.begin(), el.end());
        
        for (int i = 0; i < sorted.size(); ++i) {
            hashMap[sorted[i]].push_back(strs[i]);
        }
        
        vector<vector<string>> ans;
        for (auto&[key, v] : hashMap) {
            ans.push_back(v);
        }
        
        return ans;
    }
};