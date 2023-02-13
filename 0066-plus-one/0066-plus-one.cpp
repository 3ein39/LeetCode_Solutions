class Solution {
public:
vector<int> plusOne(vector<int> &digits) {
    long long n = digits.size();
    int last = n - 1;

    if (digits[last] < 9) {
        digits[last]++;
        return digits;
    } else {
        while (last != -1 && digits[last] == 9) {
            digits[last] = 0;
            --last;
        }
        if (last != -1)
            digits[last]++;
        else {
            vector<int> v(++n, 0);
            v[0] = 1;
            return v;
        }
        return digits;
    }
    return digits;
}

};
