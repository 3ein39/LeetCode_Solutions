class Solution {
  public:
	bool isAnagram(string s, string t) {
		unordered_map<char, int> mp;
		for (auto& el : s)
			mp[el]++;
		for (auto & el: t) {
			if (mp[el] <= 0)
				return false;
			mp[el]--;
		}
		
		for (auto& p : mp)
			if (p.second)
				return false;
		
		return true;
	}
};
