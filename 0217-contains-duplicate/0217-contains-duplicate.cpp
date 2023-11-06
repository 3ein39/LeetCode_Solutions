#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  bool containsDuplicate(vector<int>& nums) {
      unordered_set<int> hashSet;
	  for (auto& el : nums)
	    hashSet.insert(el);
	  
	  return hashSet.size() == nums.size() ? false : true; 
  }
};

// int main() {


//     return 0;
// }
