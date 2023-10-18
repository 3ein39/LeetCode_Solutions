#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int majorityElement(vector<int>& nums) {
      // O(1) space, voting algorithm
      int major = nums[0];
      int votes = 1;
      
      for (int i = 1; i < nums.size(); ++i) {
          if (votes == 0) {
              major = nums[i];
              votes = 1;
          }
          else if (major == nums[i])
            ++votes;
          else
            --votes;
            
      }
      return major;
    }   
};