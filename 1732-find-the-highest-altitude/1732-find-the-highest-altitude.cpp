class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int start = 0, ans = 0;
        for(auto& g : gain) {
            start += g;
        ans = max(ans, start);

        }
        return ans;
    }
};