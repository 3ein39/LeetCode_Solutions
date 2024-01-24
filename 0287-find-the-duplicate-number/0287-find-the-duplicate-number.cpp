class Solution {
  public:
	int findDuplicate(vector<int>& nums) {
		vector<int> freq(1e5+1, 0);
		for (auto& el : nums) freq[el]++;

		for (int i = 0; i < freq.size(); ++i) {
			if (freq[i] > 1) return i;
		}

		return 0;
	}
};
