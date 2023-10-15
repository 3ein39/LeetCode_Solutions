#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    string decodeString(string s) {
        stack<string> words;
        stack<int> cnt;
        string ans;
        int num = 0;
        
        // bool opened = false;
        
        for (auto& el : s) {
            if (el >= '0' && el <= '9')
              num = num * 10 + (el - '0');
            else if (el == '[') {
                 // reset
                 words.push(ans);
                 ans = "";
                 cnt.push(num);
                 num = 0;                
            }
            else if (el == ']') {
                string temp = ans;
                ans = words.top();
               int lp = cnt.top();
               
               words.pop();
               cnt.pop();
               
               while (lp--)
                    ans += temp;                
            }
            else {
                ans += el;
            }
            
        }
        return ans;        
    }
};