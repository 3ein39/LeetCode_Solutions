class Solution {
public:
  bool hasAllCodes(string s, int k) {
    int n = s.size();

    if (k > n)
        return false;

    set<string> subs;
    for (int i = 0; i < n - k + 1; ++i) {
        subs.insert(s.substr(i, k));
    }

    return (subs.size() == pow(2, k));
}

};