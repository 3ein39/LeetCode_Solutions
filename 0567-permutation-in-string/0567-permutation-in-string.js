/**
 * @param {string} s1
 * @param {string} s2
 * @return {boolean}
 */
var checkInclusion = function(s1, s2) {
    if (s1.length > s2.length) return false;

    let s1_freq = new Array(26).fill(0);
    let window_freq = new Array(26).fill(0);

    for (let i = 0; i < s1.length; i++) {
        s1_freq[s1[i].charCodeAt(0) - 97]++;
    }

    let [l, r] = [0, 0];
    while (r < s1.length) {
        window_freq[s2[r].charCodeAt(0) - 97]++
        r++;
    }
    r--;

    let is_equal = s1_freq.every((el, i) => {
            return el === window_freq[i]
        })
        if (is_equal) return true;

    ++l
    ++r

    while (r < s2.length) {
        window_freq[s2[l - 1].charCodeAt(0) - 97]--
        window_freq[s2[r].charCodeAt(0) - 97]++

        let is_equal = s1_freq.every((el, i) => {
            return el === window_freq[i]
        })
        if (is_equal) return true;

        ++r
        ++l
    }

    return false;
};
