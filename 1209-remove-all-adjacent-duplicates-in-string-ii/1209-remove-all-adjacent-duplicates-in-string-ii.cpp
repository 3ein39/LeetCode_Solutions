#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char, int>> st;
        for (auto& el : s) {
            if (st.empty() || st.top().first != el) st.push({el, 0});
            if (++st.top().second == k) st.pop();
        }
        
        string ans;
        while (!st.empty()) {
            auto [letter, freq] = st.top();
            st.pop();
            
            ans += string(freq, letter);
        }
        
        reverse(ans.begin(), ans.end());
        
        return ans;
    }
};