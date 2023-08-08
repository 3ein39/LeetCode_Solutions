class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        int ans = -1;

    while (l <= r) {
        int mid = l + (r - l) / 2;

        if (nums[mid] == target) return mid;
        else if (nums[l] <= nums[mid]) {
            if (target >= nums[l] && target <= nums[mid])
                r = mid - 1;
            else l = mid + 1;
        } else {
            // sorted in right half
            if (nums[r] >= target && nums[mid] <= target) l = mid + 1;
            else r = mid - 1;
        }
    }
        return ans;
    }
};