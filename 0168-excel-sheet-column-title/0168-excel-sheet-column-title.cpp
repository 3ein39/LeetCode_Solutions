    vector<char> v = {'a', 'A'};

class Solution {
public:
    string convertToTitle(int n) {
        map<char, int> mp;
        mp['A'] = 1;
        mp['B'] = 2;
        mp['C'] = 3;
        mp['D'] = 4;
        mp['E'] = 5;
        mp['F'] = 6;
        mp['G'] = 7;
        mp['H'] = 8;
        mp['I'] = 9;
        mp['J'] = 10;
        mp['K'] = 11;
        mp['L'] = 12;
        mp['M'] = 13;
        mp['N'] = 14;
        mp['O'] = 15;
        mp['P'] = 16;
        mp['Q'] = 17;
        mp['R'] = 18;
        mp['S'] = 19;
        mp['T'] = 20;
        mp['U'] = 21;
        mp['V'] = 22;
        mp['W'] = 23;
        mp['X'] = 24;
        mp['Y'] = 25;
        mp['Z'] = 26;
        
        string ans;
        while (n>0) {
            
            n--;
            ans.push_back((char)(n % 26 + 'A'));
            n /= 26;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};