/**
 * @param {number[]} nums
 * @return {number[]}
 */
var productExceptSelf = function(nums) {
    let pref = [], suff = [];
    let n = nums.length;

    pref[0] = 1, suff[n - 1] = 1;

    for (let i = 1; i < n; i++) {
        pref[i] = pref[i - 1] * nums[i - 1];
    }

    for (let i = n - 2; i >= 0; i--) {
        suff[i] = suff[i + 1] * nums[i + 1];
    }

    let ans = [];
    for (let i = 0; i < n; i++) {
        ans[i] = pref[i] * suff[i];
    }
    
    return ans;
};
