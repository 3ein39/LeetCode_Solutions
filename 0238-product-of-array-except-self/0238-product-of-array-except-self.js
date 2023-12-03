/**
 * @param {number[]} nums
 * @return {number[]}
 */
var productExceptSelf = function(nums) {
    let n = nums.length;
    
    let pref = new Array(n).fill(1), suff = new Array(n).fill(1);

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
