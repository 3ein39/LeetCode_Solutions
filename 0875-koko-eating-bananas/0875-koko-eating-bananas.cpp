class Solution {
    vector<int> v;
    int hours;
public:

    bool can(double k) {
        
      
        long long totalHrs = 0;
        for (auto& pile : v) {
            totalHrs += ceil(pile / k);
        }
        
        return totalHrs <= hours;
      
    }
    
    int minEatingSpeed(vector<int>& piles, int h) {
        v = piles;
        hours = h;
        
        
        sort(v.rbegin(), v.rend());
        
        int l = 1, r = v[0], ans = -1;
        
        while (l <= r) {
            double mid = (l + r) / 2;
            
            if (can(mid))
                ans = mid, r = mid - 1;
            else
                l = mid + 1;
        }
        
        return ans;
    }
};