#include <bits/stdc++.h>
using namespace std;


class Solution {
public:

    int lengthOfLongestSubstring(string s) {
     // variable size sliding window
     // use a hashset to see whether element is in range
     int n = s.size();
     unordered_set<char> chars;
     int l = 0;
     int ans = 0;
     for (int r = 0; r < n; ++r) {
         // if not found just add it and maximize
         if (!chars.count(s[r])) {
             chars.insert(s[r]);
             ans = max(ans, r - l + 1);
         }
         else {
             while (chars.count(s[r])) {
                 chars.erase(s[l]);
                 ++l;
             }
             chars.insert(s[r]);
         }
     }
     
     return ans;
    }
};