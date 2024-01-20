/**
 * @param {string} s
 * @return {number}
 */
var lengthOfLongestSubstring = function(s) {
    let ans = 0, cur = 0, i = 0, n = s.length;
    let seen = [];

    while (i < n) {
        if (!seen.includes(s[i]))
            seen.push(s[i]), cur++;
        else {
            while(seen[0] !== s[i])
                seen.shift(), --cur;
            seen.shift(), --cur;
            seen.push(s[i]), ++cur;
        }
        ++i;
        ans = Math.max(ans, cur);
    }
    
    return ans;
};
