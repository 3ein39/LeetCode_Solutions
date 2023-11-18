
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
    // 2 ptrs approach
    bool isPalindrome(string s) {
		// keep only alphabet & convert to lowercase
		string sanitized;
		for (auto & el : s) {
			if (el >= 'A' && el <= 'Z')
		      el += 32;
	        
	        if( (el >= 'a' && el <= 'z') || (el >= '0' && el <= '9'))
		      sanitized.push_back(el);
		}
        // cout << sanitized;
	    
	    // check if palindrome
	    int l = 0, r = sanitized.size() - 1;
	    while (l <= r) {
	        if (sanitized[l] != sanitized[r])
		        return false;
	        l++, r--;
	    }
	    
	    return true;
    }
};


