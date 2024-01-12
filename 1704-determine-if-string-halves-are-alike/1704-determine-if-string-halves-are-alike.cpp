class Solution {
public:
    bool halvesAreAlike(string s) {
        int n = s.size();
        string a = s.substr(0, n/2), b = s.substr(n/2, n);
        // cout << a << " " << b;
        
        int vo1 = 0, vo2 = 0;
        for (auto& el : a) {
            if (vowel(el)) ++vo1;
        }
        for (auto& el : b) {
            if (vowel(el)) ++vo2;
        }
        // cout << vo1<<  " " << vo2;
        return vo1 == vo2;
    }
    
    bool vowel(char el) {
        string vow = "aeiouAEIOU";
        if (vow.find(el) != string::npos)
            return true;
        return false;
    }
};