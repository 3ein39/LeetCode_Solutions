/**
 * @param {number[]} nums
 * @return {number}
 */
var numIdenticalPairs = function(nums) {
    let ans = 0;
        for (let i = 0; i < nums.length; ++i) {
            for (let j = 0; j < nums.length; ++j) {
                if (i < j && nums[i] == nums[j])
                    ++ans;
            }
        }
        return ans;
};