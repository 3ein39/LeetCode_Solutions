var removeElement = function(nums, val) {
    let cnt = 0;
    for (let i = 0; i < nums.length; ++i) {
        if (nums[i] === val) nums[i] = -1, ++cnt;
    }
    nums.sort((a, b) => b - a);
    return nums.length - cnt;
};
// removeElement([0,1,2,2,3,0,4,2], 2);
